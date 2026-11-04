
uint __fastcall FUN_00483c70(int param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  undefined1 uStack00000000;
  size_t sVar5;
  int iVar6;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  local_14 = 0;
  local_8 = 0;
  if (DAT_00a0f7f8 == '\0') {
    if (&uStack00000000 == (undefined1 *)0x18) {
      local_24 = 0xffffffff;
      __CxxThrowException_8(0xfffffff4,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_18,(void *)(DAT_00a0f830 + (int)DAT_00a11790),4);
    }
    pvVar1 = (void *)((int)DAT_00a11790 + 4);
    DAT_00a11790 = pvVar1;
  }
  else {
    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 4;
    pvVar1 = _memcpy(&local_18,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  if (local_18 < 0x80000000) {
    if (-1 < (int)local_18) {
      local_c = local_18;
    }
  }
  else {
    if ((int)local_18 < -1) {
      if (DAT_00a0f7f8 == '\0') {
        if (param_1 == -0x24) {
          local_28 = 0xffffffff;
          __CxxThrowException_8(&local_28,&DAT_00842f44);
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          _memcpy((void *)(param_1 + 0x24),(void *)(DAT_00a0f830 + (int)DAT_00a11790),4);
        }
        DAT_00a11790 = (void *)((int)DAT_00a11790 + 4);
      }
      else {
        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
          DAT_00a117e4 = 1;
          return (uint)pvVar1 & 0xffffff00;
        }
        DAT_00a0f844 = 4;
        _memcpy((void *)(param_1 + 0x24),(void *)(DAT_00a0f824 + DAT_00a0f820),4);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      }
    }
    if (0x7fffffff < local_18) {
      *(uint *)(param_1 + 0x20) = local_18;
      if (DAT_00a0f7f8 == '\0') {
        if (&uStack00000000 == (undefined1 *)0xc) {
          local_2c = 0xffffffff;
          __CxxThrowException_8(0xffffffe0,&DAT_00842f44);
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          _memcpy(&local_c,(void *)(DAT_00a0f830 + (int)DAT_00a11790),4);
        }
        DAT_00a11790 = (void *)((int)DAT_00a11790 + 4);
      }
      else {
        if (DAT_00a0f828 < DAT_00a0f820 + 4) {
          DAT_00a117e4 = 1;
          return local_18 & 0xffffff00;
        }
        DAT_00a0f844 = 4;
        _memcpy(&local_c,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      }
    }
  }
  FUN_004ce970(local_c);
  for (local_1c = 0; local_1c < (int)local_c; local_1c = local_1c + 1) {
    if (DAT_00a0f7f8 == '\0') {
      iVar3 = FUN_004ce990(local_1c);
      if (iVar3 == 0) {
        local_30 = 0xffffffff;
        __CxxThrowException_8(&local_30,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        sVar5 = 4;
        pvVar2 = (void *)(DAT_00a0f830 + (int)DAT_00a11790);
        pvVar1 = (void *)FUN_004ce990(local_1c);
        _memcpy(pvVar1,pvVar2,sVar5);
      }
      DAT_00a11790 = (void *)((int)DAT_00a11790 + 4);
    }
    else {
      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
        DAT_00a117e4 = 1;
        return 0;
      }
      DAT_00a0f844 = 4;
      sVar5 = 4;
      pvVar1 = (void *)(DAT_00a0f824 + DAT_00a0f820);
      pvVar2 = (void *)FUN_004ce990(local_1c);
      _memcpy(pvVar2,pvVar1,sVar5);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
    piVar4 = (int *)FUN_004ce990(local_1c);
    if (*piVar4 / 1000 == 1) {
      local_14 = local_14 + 1;
    }
    piVar4 = (int *)FUN_004ce990(local_1c);
    if (*piVar4 / 1000 == 2) {
      local_8 = local_8 + 1;
    }
  }
  if (DAT_00a0f7f8 == '\0') {
    if (&uStack00000000 == (undefined1 *)0x10) {
      __CxxThrowException_8(0xffffffdc,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_10,(void *)(DAT_00a0f830 + (int)DAT_00a11790),4);
    }
    DAT_00a11790 = (void *)((int)DAT_00a11790 + 4);
  }
  else {
    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 4;
    _memcpy(&local_10,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  FUN_004cfc60(local_10);
  for (local_20 = 0; local_20 < local_10; local_20 = local_20 + 1) {
    iVar3 = local_14;
    iVar6 = local_8;
    FUN_004cfcd0(local_20);
    FUN_00484190(iVar3,iVar6);
  }
  return CONCAT31((int3)((uint)local_20 >> 8),1);
}

