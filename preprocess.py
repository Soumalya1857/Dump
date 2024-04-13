import os
import json

destination = "/home/soumalya/Videos/Dataset/Kaggle audio/flatten"
fileDict = []

emo_map = {
    '01': "neutral",
    "02": "calm",
    "03": "happy",
    "04": "sad",
    "05": "angry",
    "06": "fearful",
    "07": "disgust",
    "08": "surprised"
}

fileToEmoDict = {} # unique filename -> emo

print(destination)

for root, directories, files in os.walk(destination):
    for file in files:
        fullPath = os.path.join(root, file)
        fileDict.append(file)

        # get only the emo value
        emoVal = file[6:8]
        print(emo_map.get(emoVal))

        # save 
        fileToEmoDict[file] = emo_map.get(emoVal)



print(len(fileDict))
print(json.dumps(fileToEmoDict, indent=4))







#======================================================#

from pydub import AudioSegment
# Create function to convert audio file to wav
def convert_to_wav(filename):
  """Takes an audio file of non .wav format and converts to .wav"""
  # Import audio file
  audio = AudioSegment.____(filename)
  
  # Create new filename
  new_filename = filename.split(".")[0] + ".wav"
  
  # Export file as .wav
  audio.export(new_filename, format=____)
  print(f"Converting {filename} to {new_filename}...")
 
# Test the function
convert_to_wav(____)

#============================================================#

def load_model():
    filePath = "/path/to/.keras/file" #check here
    loaded_model = tf.keras.models.load_model(filePath)
    return loaded_model

# predict code
def predict(model=model, audioPath=""):

    audioWav = convert_to_wav(audioPath)

    emo_map = {0: "happy", 1: "neutral", 2: "sad"}
    feature = audioPath
    sampling_rate
    X, sample_rate_1= librosa.load(feature,sr=sampling_rate*2,offset=0.5, res_type='scipy')
    sample_rate_1 = np.array(sample_rate_1)
    mfccs = np.mean(librosa.feature.mfcc(y=X,
                                         sr=sample_rate_1,
                                         n_mfcc=13),
                                         axis=0)
    feature = mfccs

    feature = np.pad(feature, (0, 412-len(feature)), 'constant') if len(feature) < 412 else feature[:412]
    feature = np.array([feature])
    print(feature.shape)
    
    # predict with the model
    prediction = model.predict([feature])
    pred = np.argmax(prediction, axis=1)
    emotion = emo_map[pred[0]]
    print("emotion: ", emotion)
    return emotion

print(predict(load_model(), audioPath='/content/flatten/03-01-05-02-01-01-11.wav'))



!gsutil cp -r gs://audio-sentiment-detection-dataset/saved_models/Emotion_Voice_Detection_Model content/ 
