const AWS = require('aws-sdk')

const firehose = new AWS.Firehose()
const StreamName = "PUT-S3-3VG0q"

exports.handler = async (event) => {
    
    console.log('Received IoT event:', JSON.stringify(event, null, 2))
    
    let payload = {
        macId: event.macId,
        temperature: event.temperature,
        humidity: event.humidity,
        voc: event.voc,
        ts: new Date(event.timeStamp *1000)
    }
    
    let params = {
            DeliveryStreamName: StreamName,
            Record: { 
                Data: JSON.stringify(payload)
            }
        }
        
    return await firehose.putRecord(params).promise()

}