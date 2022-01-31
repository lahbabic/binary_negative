import sys 

def calculate_binary_negative(binary_positive):
    result = 0  
    mag = []
    if binary_positive[0] == 0:
        tmp = 0
    elif binary_positive[0] == 1:
        tmp = 1
    invert = invert_binary(binary_positive)
    mag.append(tmp)
    [mag.append(x) for x in invert]
    if mag[0] == 0:
        for i in range(1,len(mag)):
            result += pow(2,len(mag)-i-1)*mag[i]
        result -=  pow(2,len(mag)-1)
        result += 1
    elif mag[0] == 1:
        for i in range(1, len(mag)):
            result -= pow(2,len(mag)-i-1)*mag[i]
        result +=  pow(2,len(mag)-2)
        result -= 1
    return result

def invert_binary(binary):
	tmp = []
	for x in binary:
		if x == 1: 
			tmp.append(0)
		elif x == 0: 
			tmp.append(1)
	return tmp

def decimal_to_binary(decimal):
    try:
        decimal = int(decimal)
    except:
        print("Enter a decimal number, please.")
        exit(2)
    binary = bin(decimal)
    tmp = []
    if str(binary).split('b')[0].strip('0') == "":
        tmp.append(0)
    elif str(binary).split('b')[0].strip('0') == "-":
        tmp.append(1)
    binary = str(binary).split('b')[1]
    for x in binary:
        tmp.append(int(x))
    return tmp

def main():
	if len(sys.argv) < 2:
		print("usage: python3 binary_negative.py 8")
		exit(1)
	num = sys.argv[1]
	invert = []	
	binary_positive = decimal_to_binary(num)
	result = calculate_binary_negative(binary_positive)
	print(result)

if __name__ == '__main__':
	main()
