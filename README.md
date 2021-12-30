<center><h1>
    <div>CloudService_AQI</div>
</h1>
    <h4>
        <div>Olle Johansson</div>
        <div>Nackademin, IoT20</div>
        <div>IoT & Molntjänster</div>
    </h3>
</center>

## Inledning
<div>
    <details>
        <summary>Bakgrund</summary>
            Att med hjälp av sensorer övervaka hur luftkvalitén inomhus ser ut över tid, samt nyttja ett API för att utöka insamlad data med mätningar av skadliga partiklar i luften utomhus.
    </details>
</div>

<div>
    <details>
        <summary> Mål </summary>
            Bredda kompetensen genom att testa en molntjänst jag inte använt innan (AWS).
            Få en tydlig överblick på uppmätta luftburna partiklar inom- och utomhus.
    </details>
</div>

## Systemskiss
[![Systemskiss](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/e724e95e-a84b-4c3f-a943-4309c46b6724/Untitled_Diagram.jpg?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20211230%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20211230T124210Z&X-Amz-Expires=86400&X-Amz-Signature=aab0db48f43d34566883ea1834ec81cbe3f2d96826939ecd7306812f18a51a5b&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled%2520Diagram.jpg%22&x-id=GetObject)

## Använda program/libraries/hårdvara

<details>
    <summary> Libraries</summary>
            <blockquote>
                    <div>Adafruit_Unified_Sensor</div>
                    <div>ArduinoBearSSL</div>
                    <div>ArduinoECCX08</div>
                    <div>ArduinoJson</div>
                    <div>DHT_sensor_library</div>
                    <div>RTCZero</div>
                    <div>SparkFun_SGP40_Arduino_Library</div>
                    <div>SPI</div>
                    <div>WiFiNINA</div>
                    <div>Wire</div>
            </blockquote>
    </details>
<details>
    <summary> Program </summary>
        <blockquote>
            <div>VS Code med Arduino-extension</div>
            <div>Node-Red</div>
        </blockquote>
    </details>
<details>
    <summary>Hårdvara</summary>
        <blockquote>
            <div>Arduino MKR WiFi 1010</div>
            <div>Sparkfun SGP40 VOC-sensor</div>
            <div>Adafruit DHT11 sensor</div>
        </blockquote>
    </details>
</details>

## Kod-länkar
>[Arduino-kod](AWS_IoT_WiFi.ino)

>[Lambda function-kod](ArduinoConsumeMessages/index.js)
## Visualisering av data
[Quicksight](https://eu-west-1.quicksight.aws.amazon.com/sn/start/analyses)
