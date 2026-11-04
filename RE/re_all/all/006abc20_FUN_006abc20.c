
undefined1 FUN_006abc20(undefined4 *param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  short local_1c [4];
  undefined1 local_14 [20];
  
  if (((param_1 == (undefined4 *)0x0) ||
      (FUN_007976d0(local_14,*param_1,param_1[1]), param_1[2] == 0)) ||
     (iVar3 = FUN_00797830(local_14,8), iVar3 != 1)) {
    return 0;
  }
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[2] = 0;
  FUN_006abca0(local_14,local_1c,6);
  iVar3 = 3;
  psVar4 = local_1c;
  psVar5 = (short *)s_vorbis_00a0ef60;
  do {
    if (iVar3 == 0) {
      return 1;
    }
    iVar3 = iVar3 + -1;
    sVar2 = *psVar5;
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
    psVar5 = psVar5 + 1;
  } while (sVar1 == sVar2);
  return 0;
}

