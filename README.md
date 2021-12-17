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
[![Systemskiss](https://api-data-bucket1.s3.eu-west-1.amazonaws.com/Untitled%20Diagram.jpg?response-content-disposition=inline&X-Amz-Security-Token=IQoJb3JpZ2luX2VjELn%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FwEaCmV1LW5vcnRoLTEiRjBEAiB74UxutZ1qDOAzRoI9wzPWhw0IHSiJ9FpiwjcK%2B7xSkAIgC0u2ijXz9UWycPcMaVbhiAFSAlITnosLaVDyWepwi4sq%2FwIIov%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FARAAGgw1NDM1NjMyNDYyNDEiDAaTueBkZYvSP%2FLpvirTArdvYELR2fgWUgSVu%2FtE%2FJAiZJrwIrD8nxHyLujvkkmYJpV67kmHjZzT%2BTStySTr8i5e%2FXRETwe1UZ7K4q2LIA4HoOBUEIJldhPE0djjm1XXulGppPU%2BqJECVfS%2B5dNyM1AtfWQJ87gaq%2F7Ph1xyuMkPnEHKKlmPv%2B%2F8TSxSulKr2CRfTxlQSFmotZO5lDfvWhRzKSV%2BIqtGcCR6IqekRsRVdsqoalxByYElePVmfh%2B547sD8p3noOMuz9XqE%2BYqFZiRC3aBZgc4LtdFgvVJLAXUg0tB5TILcm1bcar2yki%2BJa5hlqtd9dSOSxpqfjYHwX6dWZPM6XT6I2319XoOvnQzbnDMDpTyBCW%2B2SLTmP4lL%2F3z%2BljHa9S5MMhs%2Fl2529vTh%2BYzOZCN2S2ye6dCdrRDG9qxQhDF0058c%2FNREDbIWGcDYU34qzArnvLmX8b%2BqC%2B19jCvnvGNBjq0AiayQpuTdzsEDnjLt1erx5RhLxOlXQuHmHt9Ef%2BuJRmbDr9kW2GveNXI8NCIUB2KkCfA4sMXXNDKHzpGXbjexrFgdtFBr%2BIQC%2Fjcl5OAlIlGqe92nvgalDc4dQeN0uLRJBT5%2Fvv2Px9jkHgOo8zJ94%2FATzCE99D%2FcwwepX46CWuzJEozemYvufegfG1Xy8X1RS7fuMzRDFayJ1z15v7cIvGmOBvfZKyMhxR%2Fpr6ZO9GatEmlyYpfFFw8yxMgV0h5jgtJ24vBQooNMPKV6Ad56F5quBqv8MafX9jh6gLqa9%2B5H2dxh7bQJraNF6BG3b%2FSZYrsRwYrAKOoxqlQySo2pkxzSgB6msC7Ai%2BaqjgHURRpm13x73nBrGtiiWruLAnPZxD7fpnyZLs53unqZHPa2RDNyjaT&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20211217T134634Z&X-Amz-SignedHeaders=host&X-Amz-Expires=604800&X-Amz-Credential=ASIAX5DXE5KQ7JGJ2IWU%2F20211217%2Feu-west-1%2Fs3%2Faws4_request&X-Amz-Signature=87e73747e200129edc9007762a355405f95ac96cd87dbdbc3eb0ee33c9652bb6)](https://api-data-bucket1.s3.eu-west-1.amazonaws.com/Untitled%20Diagram.jpg?response-content-disposition=inline&X-Amz-Security-Token=IQoJb3JpZ2luX2VjELn%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FwEaCmV1LW5vcnRoLTEiRjBEAiB74UxutZ1qDOAzRoI9wzPWhw0IHSiJ9FpiwjcK%2B7xSkAIgC0u2ijXz9UWycPcMaVbhiAFSAlITnosLaVDyWepwi4sq%2FwIIov%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FARAAGgw1NDM1NjMyNDYyNDEiDAaTueBkZYvSP%2FLpvirTArdvYELR2fgWUgSVu%2FtE%2FJAiZJrwIrD8nxHyLujvkkmYJpV67kmHjZzT%2BTStySTr8i5e%2FXRETwe1UZ7K4q2LIA4HoOBUEIJldhPE0djjm1XXulGppPU%2BqJECVfS%2B5dNyM1AtfWQJ87gaq%2F7Ph1xyuMkPnEHKKlmPv%2B%2F8TSxSulKr2CRfTxlQSFmotZO5lDfvWhRzKSV%2BIqtGcCR6IqekRsRVdsqoalxByYElePVmfh%2B547sD8p3noOMuz9XqE%2BYqFZiRC3aBZgc4LtdFgvVJLAXUg0tB5TILcm1bcar2yki%2BJa5hlqtd9dSOSxpqfjYHwX6dWZPM6XT6I2319XoOvnQzbnDMDpTyBCW%2B2SLTmP4lL%2F3z%2BljHa9S5MMhs%2Fl2529vTh%2BYzOZCN2S2ye6dCdrRDG9qxQhDF0058c%2FNREDbIWGcDYU34qzArnvLmX8b%2BqC%2B19jCvnvGNBjq0AiayQpuTdzsEDnjLt1erx5RhLxOlXQuHmHt9Ef%2BuJRmbDr9kW2GveNXI8NCIUB2KkCfA4sMXXNDKHzpGXbjexrFgdtFBr%2BIQC%2Fjcl5OAlIlGqe92nvgalDc4dQeN0uLRJBT5%2Fvv2Px9jkHgOo8zJ94%2FATzCE99D%2FcwwepX46CWuzJEozemYvufegfG1Xy8X1RS7fuMzRDFayJ1z15v7cIvGmOBvfZKyMhxR%2Fpr6ZO9GatEmlyYpfFFw8yxMgV0h5jgtJ24vBQooNMPKV6Ad56F5quBqv8MafX9jh6gLqa9%2B5H2dxh7bQJraNF6BG3b%2FSZYrsRwYrAKOoxqlQySo2pkxzSgB6msC7Ai%2BaqjgHURRpm13x73nBrGtiiWruLAnPZxD7fpnyZLs53unqZHPa2RDNyjaT&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20211217T134634Z&X-Amz-SignedHeaders=host&X-Amz-Expires=604800&X-Amz-Credential=ASIAX5DXE5KQ7JGJ2IWU%2F20211217%2Feu-west-1%2Fs3%2Faws4_request&X-Amz-Signature=87e73747e200129edc9007762a355405f95ac96cd87dbdbc3eb0ee33c9652bb6)

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