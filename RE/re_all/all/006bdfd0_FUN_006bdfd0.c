
int FUN_006bdfd0(undefined4 param_1,int param_2,int param_3,int *param_4,int param_5)

{
  uint uVar1;
  void *_Memory;
  int iVar2;
  short *psVar3;
  short *psVar4;
  bool bVar5;
  short local_8 [4];
  
  uVar1 = FUN_006bf0c0(param_1,8);
  if (((((uVar1 & 0x80) == 0) && (*(int *)(param_2 + 4) != 0)) && (*(int *)(param_3 + 0xc) != 0)) &&
     (*param_4 != 0)) {
    return 0;
  }
  FUN_006be1b0(param_1,local_8,6);
  iVar2 = 3;
  bVar5 = true;
  psVar3 = local_8;
  psVar4 = (short *)(s__theora_00a0f393 + 1);
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *psVar3 == *psVar4;
    psVar3 = psVar3 + 1;
    psVar4 = psVar4 + 1;
  } while (bVar5);
  if (!bVar5) {
    return -0x15;
  }
  if (uVar1 == 0x80) {
    if ((*(int *)(param_5 + 8) != 0) && (*(int *)(param_2 + 4) == 0)) {
      iVar2 = FUN_006be1e0(param_1,param_2);
      if (iVar2 < 0) {
        FUN_006b8ec0(param_2);
        return iVar2;
      }
      return 3;
    }
  }
  else if (uVar1 == 0x81) {
    if (param_3 == 0) {
      return -1;
    }
    if ((*(int *)(param_2 + 4) != 0) && (*(int *)(param_3 + 0xc) == 0)) {
      iVar2 = FUN_006be360(param_1,param_3);
      if (iVar2 < 0) {
        FUN_006b8ed0(param_3);
        return iVar2;
      }
      return 2;
    }
  }
  else if (uVar1 == 0x82) {
    if ((param_3 != 0) && (param_4 != (int *)0x0)) {
      if (*(int *)(param_2 + 4) == 0) {
        return -0x14;
      }
      if (*(int *)(param_3 + 0xc) == 0) {
        return -0x14;
      }
      if (*param_4 != 0) {
        return -0x14;
      }
      _Memory = _calloc(1,0x2c8);
      if (_Memory != (void *)0x0) {
        iVar2 = FUN_006be510(param_1,_Memory);
        if (iVar2 < 0) {
          FUN_006be540(_Memory);
          _free(_Memory);
          return iVar2;
        }
        *param_4 = (int)_Memory;
        return 1;
      }
    }
    return -1;
  }
  return -0x14;
}

