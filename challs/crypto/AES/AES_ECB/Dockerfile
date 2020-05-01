FROM tiangolo/meinheld-gunicorn-flask:python3.6

ENV STATIC_URL /static
ENV STATIC_PATH /var/www/app/static

ADD ./www /app

RUN sed -i 's/FLAGFLAGFLAGFLAGFLAGFLAGFLAGFLAG/199e78fd6e48b558408b7ef11b6384f637e8e78e005ee9955d0aaefa1b64d39d363e492be19d67e854e6425086311d51/' /app/app/templates/flag.html

RUN pip install -r /app/requirements.txt
