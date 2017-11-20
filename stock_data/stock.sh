#! /bin/sh

wget "http://www.google.com/finance/historical?q=KRX%3AKOSPI&output=csv" -O kospi.txt
wget "http://www.google.com/finance/historical?q=KRX:005930&output=csv" -O Samsung_Electronics.txt
wget "http://www.google.com/finance/historical?q=KRX:034220&output=csv" -O LG_Display.txt
