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
[![Systemskiss](https://api-data-bucket1.s3.eu-west-1.amazonaws.com/Untitled%20Diagram.jpg?response-content-disposition=inline&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEAAaCmV1LW5vcnRoLTEiRjBEAiAv431w1pTXCZPqta31k0lWM5KJsKgbXmVa07%2FIZOBsNQIgG7WQ4bKt048ZyPyy1bbVEAhnaB4D9COpeLGmrZCu%2BPkq%2FwII6v%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FARAAGgw1NDM1NjMyNDYyNDEiDKbjM2p%2BoJ%2BfWkPEUirTAtx6Gvnpd7bmImpPQ9n7F6Irk1Omn6KMTEFUhz8aq9bev%2BCfI7whJb%2BTLMhFSqddsMYxlmhZEB7Cf99wKYjJnNSzXEC1j%2FXogBsXyrCVApREGp8%2FMTzEBByBlJVuUnBU26IRib5hgYpUU0K7Nsp9dHCx1KHyPOWQqkgQMBO37Ptad63%2FS5jUOTGYAlZ02Huz88b387tmskXePSraLxguNyoeRrZiWuDPhtWEJJtYYrYrfsbnfaXTb3f5CajXgBJXRMEPOeZ32vPBw%2FtMKQwk6vyBztlLUs%2BGbeKrwIRHkQoA6dxv5CQ5gOpixxrpngJhqf0e%2FxOI8wqxkRyi2OviUKcDtxELXcm2oSPfn2jBHL7StjULU7eQpO%2BWutWy4mP10jhwnJzc2uwoGCpqCEQIxd%2B29kIFaGLzzk6yfbv5EQV9aBGEBJcBZUJwdbhk%2Bm%2B7iuzXmTD1%2BYCOBjq0AlVltRxVFnLV2UgippRiR2HP2M9gp8tFd%2FmgNoKUz6s2u1vZNw3lGyugU57FWY7izo6pS4ZivfvrkaMbMRQopmP1QbaItMtYBqD86cFyo1W%2Bv8%2FYfrfVs1P9PvFEWPt2MiFXpLmqRgb2Jn72YbZ8LOqnoGwkz4B2YnMKlUqLk5STGGOL8ZFvh9WDspbA0yYtLlnndJu1RcO7TbU9ujUZzCNKKV5nB70V4kM0F6H47eFCN9486aGidZmbBc%2Fo8kAVQIr9OaZXXME9Hrhf0faNQ7Clz6wHrWZLWgQLx6S%2FpatswqDTjmM0Vx61xSUYN3ofU3lRPKNpNQTGDfNFq2fwzScf7MxJUGveJYoykFcIXwFEU1L8aZwmSwnD2IG1XTuclFGWuHAQd9zsNQ%2FsupBsA9GWHild&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20211220T083258Z&X-Amz-SignedHeaders=host&X-Amz-Expires=604800&X-Amz-Credential=ASIAX5DXE5KQUIMYSQN2%2F20211220%2Feu-west-1%2Fs3%2Faws4_request&X-Amz-Signature=559db48e81850ab1e5e36c9e55470601105ea34aa84cc055174914758e0b7574)](https://api-data-bucket1.s3.eu-west-1.amazonaws.com/Untitled%20Diagram.jpg?response-content-disposition=inline&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEAAaCmV1LW5vcnRoLTEiRjBEAiAv431w1pTXCZPqta31k0lWM5KJsKgbXmVa07%2FIZOBsNQIgG7WQ4bKt048ZyPyy1bbVEAhnaB4D9COpeLGmrZCu%2BPkq%2FwII6v%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FARAAGgw1NDM1NjMyNDYyNDEiDKbjM2p%2BoJ%2BfWkPEUirTAtx6Gvnpd7bmImpPQ9n7F6Irk1Omn6KMTEFUhz8aq9bev%2BCfI7whJb%2BTLMhFSqddsMYxlmhZEB7Cf99wKYjJnNSzXEC1j%2FXogBsXyrCVApREGp8%2FMTzEBByBlJVuUnBU26IRib5hgYpUU0K7Nsp9dHCx1KHyPOWQqkgQMBO37Ptad63%2FS5jUOTGYAlZ02Huz88b387tmskXePSraLxguNyoeRrZiWuDPhtWEJJtYYrYrfsbnfaXTb3f5CajXgBJXRMEPOeZ32vPBw%2FtMKQwk6vyBztlLUs%2BGbeKrwIRHkQoA6dxv5CQ5gOpixxrpngJhqf0e%2FxOI8wqxkRyi2OviUKcDtxELXcm2oSPfn2jBHL7StjULU7eQpO%2BWutWy4mP10jhwnJzc2uwoGCpqCEQIxd%2B29kIFaGLzzk6yfbv5EQV9aBGEBJcBZUJwdbhk%2Bm%2B7iuzXmTD1%2BYCOBjq0AlVltRxVFnLV2UgippRiR2HP2M9gp8tFd%2FmgNoKUz6s2u1vZNw3lGyugU57FWY7izo6pS4ZivfvrkaMbMRQopmP1QbaItMtYBqD86cFyo1W%2Bv8%2FYfrfVs1P9PvFEWPt2MiFXpLmqRgb2Jn72YbZ8LOqnoGwkz4B2YnMKlUqLk5STGGOL8ZFvh9WDspbA0yYtLlnndJu1RcO7TbU9ujUZzCNKKV5nB70V4kM0F6H47eFCN9486aGidZmbBc%2Fo8kAVQIr9OaZXXME9Hrhf0faNQ7Clz6wHrWZLWgQLx6S%2FpatswqDTjmM0Vx61xSUYN3ofU3lRPKNpNQTGDfNFq2fwzScf7MxJUGveJYoykFcIXwFEU1L8aZwmSwnD2IG1XTuclFGWuHAQd9zsNQ%2FsupBsA9GWHild&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20211220T083258Z&X-Amz-SignedHeaders=host&X-Amz-Expires=604800&X-Amz-Credential=ASIAX5DXE5KQUIMYSQN2%2F20211220%2Feu-west-1%2Fs3%2Faws4_request&X-Amz-Signature=559db48e81850ab1e5e36c9e55470601105ea34aa84cc055174914758e0b7574)

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