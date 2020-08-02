test = int(input())
for i in range(test):
  arrival = []
  departure = []
  train = int(input())
  for i in range(train):
    arrival.append(int(input()))
  for j in range(train):
    departure.append(int(input()))
  arr1 = []
  dep1 = []
  for i in range(train):
    if(len(arr1)==0):
      arr1.append(arrival[0])
      dep1.append(departure[0])
    else:
      buff = 0
      for j in range(len(arr1)):
        if(arrival[i]<=dep1[j]):
              buff+=1
        else:
            arr1[j] = arrival[i]
            dep1[j] = departure[i]
            break
      if(buff==len(arr1)):
          arr1.append(arrival[i])
          dep1.append(departure[i])
  print(arr1)