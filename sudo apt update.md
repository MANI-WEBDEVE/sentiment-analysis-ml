
sudo apt update

sudo apt install python3-pip

sudo apt install pipenv

sudo apt install virtualenv

mkdir mlflow

cd mlflow

pipenv install mlflow

pipenv install awscli

pipenv install boto3

pipenv shell

mlflow server \
    --host 0.0.0.0 \
    --port 5000 \
    --default-artifact-root s3://mlflow-server-bucket-2025 \
    --allowed-hosts "*" 


# to allow cross origin
mlflow server \
    --host 0.0.0.0 \
    --port 5000 \
    --default-artifact-root s3://mlflow-server-bucket-2025 \
    --allowed-hosts "*" \
    --cors-allowed-origins "*"
