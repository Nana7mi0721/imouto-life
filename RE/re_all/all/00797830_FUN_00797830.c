
uint FUN_00797830(int *param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_2 < 0) || (0x20 < param_2)) {
LAB_0079791a:
    param_1[3] = 0;
    *param_1 = param_1[4];
    param_1[1] = 1;
    return 0xffffffff;
  }
  uVar1 = *(uint *)(&DAT_008375b4 + param_2 * 4);
  iVar4 = param_1[1];
  uVar6 = param_2 + iVar4;
  if (param_1[4] + -4 <= *param_1) {
    if (param_1[4] - ((int)(uVar6 + 7) >> 3) < *param_1) goto LAB_0079791a;
    if (uVar6 == 0) {
      return 0;
    }
  }
  pbVar2 = (byte *)param_1[3];
  uVar5 = (uint)(*pbVar2 >> (*(byte *)(param_1 + 1) & 0x1f));
  if ((((8 < (int)uVar6) &&
       (cVar3 = (char)iVar4, uVar5 = uVar5 | (uint)pbVar2[1] << (8U - cVar3 & 0x1f),
       0x10 < (int)uVar6)) &&
      (uVar5 = uVar5 | (uint)pbVar2[2] << (0x10U - cVar3 & 0x1f), 0x18 < (int)uVar6)) &&
     ((uVar5 = uVar5 | (uint)pbVar2[3] << (0x18U - cVar3 & 0x1f), 0x20 < (int)uVar6 && (iVar4 != 0))
     )) {
    uVar5 = uVar5 | (uint)pbVar2[4] << (0x20U - cVar3 & 0x1f);
  }
  param_1[1] = uVar6 & 7;
  iVar4 = (int)(uVar6 + ((int)uVar6 >> 0x1f & 7U)) >> 3;
  param_1[3] = (int)(pbVar2 + iVar4);
  *param_1 = iVar4 + *param_1;
  return uVar5 & uVar1;
}

