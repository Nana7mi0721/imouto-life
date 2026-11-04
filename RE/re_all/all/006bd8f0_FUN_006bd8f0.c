
undefined4 FUN_006bd8f0(int param_1,int *param_2,int param_3,short param_4)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 0x240 + param_3 * 4);
  if ((param_3 == 0) || ((*(byte *)(param_1 + 0x30) & 2) != 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  iVar5 = ((int)param_4 >> 8) + iVar5 * 0x40;
  cVar1 = (&DAT_008323cf)[iVar5];
  if ((param_3 == 0) || ((*(byte *)(param_1 + 0x30) & 1) != 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = 1;
  }
  iVar4 = iVar4 * 0x40 + (int)(char)param_4;
  cVar2 = (&DAT_008323cf)[iVar4];
  iVar5 = (int)(char)(&DAT_0083234f)[iVar4] + (char)(&DAT_0083234f)[iVar5] * iVar3;
  if ((cVar2 == 0) && (cVar1 == 0)) {
    *param_2 = iVar5;
    return 1;
  }
  *param_2 = iVar5;
  param_2[1] = cVar1 * iVar3 + iVar5 + (int)cVar2;
  return 2;
}

