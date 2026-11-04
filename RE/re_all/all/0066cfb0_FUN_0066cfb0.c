
void FUN_0066cfb0(int param_1,int *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  sbyte sVar5;
  
  if (((int)(uint)*(ushort *)(param_1 + 0x148) < 1 << (*(byte *)((int)param_2 + 9) & 0x1f)) &&
     (*(ushort *)(param_1 + 0x148) != 0)) {
    pbVar1 = *(byte **)(param_1 + 0x124);
    uVar3 = -((uint)*(byte *)((int)param_2 + 0xb) * *param_2) & 7;
    pbVar2 = pbVar1 + param_2[1];
    switch(*(byte *)((int)param_2 + 9)) {
    case 1:
      if (pbVar1 < pbVar2) {
        do {
          if (*pbVar2 >> (sbyte)uVar3 != 0) {
            *(undefined4 *)(param_1 + 0x14c) = 1;
          }
          uVar3 = 0;
          pbVar2 = pbVar2 + -1;
        } while (pbVar1 < pbVar2);
        return;
      }
      break;
    case 2:
      if (pbVar1 < pbVar2) {
        do {
          sVar5 = (sbyte)uVar3;
          uVar3 = *pbVar2 >> sVar5 & 3;
          if (*(int *)(param_1 + 0x14c) < (int)uVar3) {
            *(uint *)(param_1 + 0x14c) = uVar3;
          }
          uVar3 = (byte)((*pbVar2 >> sVar5) >> 2) & 3;
          if (*(int *)(param_1 + 0x14c) < (int)uVar3) {
            *(uint *)(param_1 + 0x14c) = uVar3;
          }
          uVar3 = (byte)((*pbVar2 >> sVar5) >> 4) & 3;
          if (*(int *)(param_1 + 0x14c) < (int)uVar3) {
            *(uint *)(param_1 + 0x14c) = uVar3;
          }
          uVar3 = (uint)(byte)((*pbVar2 >> sVar5) >> 6);
          if (*(int *)(param_1 + 0x14c) < (int)uVar3) {
            *(uint *)(param_1 + 0x14c) = uVar3;
          }
          uVar3 = 0;
          pbVar2 = pbVar2 + -1;
        } while (pbVar1 < pbVar2);
        return;
      }
      break;
    case 4:
      if (pbVar1 < pbVar2) {
        do {
          uVar4 = *pbVar2 >> (sbyte)uVar3 & 0xf;
          if (*(int *)(param_1 + 0x14c) < (int)uVar4) {
            *(uint *)(param_1 + 0x14c) = uVar4;
          }
          uVar3 = (uint)(byte)((*pbVar2 >> (sbyte)uVar3) >> 4);
          if (*(int *)(param_1 + 0x14c) < (int)uVar3) {
            *(uint *)(param_1 + 0x14c) = uVar3;
          }
          uVar3 = 0;
          pbVar2 = pbVar2 + -1;
        } while (pbVar1 < pbVar2);
        return;
      }
      break;
    case 8:
      for (; pbVar1 < pbVar2; pbVar2 = pbVar2 + -1) {
        if (*(int *)(param_1 + 0x14c) < (int)(uint)*pbVar2) {
          *(uint *)(param_1 + 0x14c) = (uint)*pbVar2;
        }
      }
    }
  }
  return;
}

