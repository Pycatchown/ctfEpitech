from flask import Response, render_template, request
from Crypto.Util.Padding import pad, unpad
from Crypto.Cipher import AES
from json import dumps
import os, base64
from app import app

BLOCK_SIZE = 16
KEY = os.urandom(16)
IV = os.urandom(16)

@app.route('/')
def home():
   return render_template("home.html")

@app.route('/encrypt', methods=["POST"])
def encrypt():
   json = request.json
   if 'is_admin=True' in json['plaintext']:
      return Response(dumps({'ciphertext': 'Nein, nein, nein, mein lieber Freund!'}))
   es = AES.new(KEY, AES.MODE_CBC, IV)
   ciphertext = base64.b64encode(es.encrypt(pad(json['plaintext'].encode(),
                                                BLOCK_SIZE))).decode()
   return Response(dumps({'ciphertext': ciphertext}))

@app.route('/decrypt', methods=["POST"])
def decrypt():
   json = request.json
   ds = AES.new(KEY, AES.MODE_CBC, IV)
   plaintext = unpad(ds.decrypt(base64.b64decode(json['ciphertext'].encode())),
                     BLOCK_SIZE).decode()
   return Response(dumps({'plaintext': plaintext}))

@app.route('/flag', methods=["POST"])
def flag():
   ds = AES.new(KEY, AES.MODE_CBC, IV)
   t = request.form.get("token")
   try:
      auth = unpad(ds.decrypt(base64.b64decode(t)), BLOCK_SIZE)
   except Exception:
      return render_template('notflag.html')
   return render_template('flag.html' if b'is_admin=True' in auth else 'notflag.html') 
