import math

mp = {'A': 3, 'B': 2, 'C': 1}

def _class(ipl):
    if ipl[0] >= 0 and ipl[0] <= 127:
        return 'A'
    elif ipl[0] >= 128 and ipl[0] <= 191:
        return'B'
    elif ipl[0] >= 192 and ipl[0] <= 223:
        return 'C'
    elif ipl[0] >= 224 and ipl[0] <= 239:
        return 'D'
    elif ipl[0] >= 240 and ipl[0] <= 255:
        return 'E'

# return network id, broadcast address respectively
def props(ipl, cl):
    if cl == 'A':
        return f'{ipl[0]}', f'{ipl[0]}.255.255.255'
    elif cl == 'B':
        return f'{ipl[0]}.{ipl[1]}', f'{ipl[0]}.{ipl[1]}.255.255'
    elif cl == 'C':
        return f'{ipl[0]}.{ipl[1]}.{ipl[2]}', f'{ipl[0]}.{ipl[1]}.{ipl[2]}.255'

def subnet_mask(cl, exp):
    mask_bin = ''
    if cl == 'A':
        mask_bin = (8+exp)*'1' + (24-exp)*'0'
    elif cl == 'B':
        mask_bin = (16+exp)*'1' + (16-exp)*'0'
    elif cl == 'C':
        mask_bin = (24+exp)*'1' + (8-exp)*'0'

    subl = [int(mask_bin[i:i+8], 2) for i in range(0, len(mask_bin), 8)]
    return f'{subl[0]}.{subl[1]}.{subl[2]}.{subl[3]}'

def subnetting(netid, cl, s):
    each = (256**mp[cl])//s

    if cl == 'A':
        for i in range(0, 256):
            for j in range(0, 256):
                for k in range(0, 256, each):
                    print(f'Subnet Address: {netid}.{i}.{j}.{k}')
                    print(f'Broadcast Address: {netid}.{i}.{j}.{k+each-1}')
                    print(f'Valid host IP range: {netid}.{i}.{j}.{k+1} to {netid}.{i}.{j}.{k+each-2}\n')
    
    elif cl == 'B':
        for j in range(0, 256):
            for k in range(0, 256, each):
                print(f'Subnet Address: {netid}.{j}.{k}')
                print(f'Broadcast Address: {netid}.{j}.{k+each-1}')
                print(f'Valid host IP range: {netid}.{j}.{k+1} to {netid}.{j}.{k+each-2}\n')
    
    elif cl == 'C':
        for k in range(0, 256, each):
            print(f'Subnet Address: {netid}.{k}')
            print(f'Broadcast Address: {netid}.{k+each-1}')
            print(f'Valid host IP range: {netid}.{k+1} to {netid}.{k+each-2}\n')

ip = input('Enter IP address: ')
ipl = list(map(int, ip.split('.')))

cl = _class(ipl)
print(f'Class: {cl}')
res = props(ipl, cl)
print(f'Network Id: {res[0]}')
print(f'Broadcast Address: {res[1]}')

s = int(input('Enter number of subnets: '))
exp = math.log2(s)
if exp != int(exp):
    exp = int(exp)+1
else:
    exp = int(exp)
s = 2**exp

print(f'Subnet Mask: {subnet_mask(cl, exp)}\n')
subnetting(res[0], cl, s)
