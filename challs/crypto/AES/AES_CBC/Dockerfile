FROM tiangolo/meinheld-gunicorn-flask:python3.6

ENV STATIC_URL /static
ENV STATIC_PATH /var/www/app/static

ADD ./www /app

RUN sed -i 's/FLAGFLAGFLAGFLAGFLAGFLAGFLAGFLAG/201a72daca14faa956bce629745995c8143dca3c5cf6d0b60064ab58878123f949d59d36342df11d5f77cc7298c46dd9/' /app/app/templates/flag.html

RUN pip install -r /app/requirements.txt

EXPOSE 80