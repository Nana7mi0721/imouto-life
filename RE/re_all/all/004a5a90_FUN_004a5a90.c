
int FUN_004a5a90(undefined4 param_1,int param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 uStack00000000;
  int local_28;
  int local_18;
  int local_14;
  int local_10;
  size_t local_c;
  int local_8;
  
  local_8 = FUN_0052e3c0(param_1,0);
  if (local_8 == 0) {
    local_10 = -1;
  }
  else {
    local_c = FUN_0052c9a0(param_1);
    DAT_00a11790 = 0;
    if (DAT_00a117ec == 0) {
      DAT_00a0f830 = _malloc(local_c);
      _memset(DAT_00a0f830,0,local_c);
    }
    FUN_0052cde0(DAT_00a0f830,local_c,local_8);
    thunk_FUN_00580b80(local_8);
    if (&uStack00000000 == (undefined1 *)0x14) {
      __CxxThrowException_8(0xfffffff8,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_14,(void *)((int)DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    if (local_14 == 0x30c386c) {
      if (&uStack00000000 == (undefined1 *)0x10) {
        __CxxThrowException_8(0xfffffff0,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_10,(void *)((int)DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      if (param_3 != '\0') {
        iVar3 = param_2 + local_10;
        iVar1 = FUN_004cfab0();
        if (iVar1 < iVar3) {
          local_28 = param_2 + local_10;
        }
        else {
          local_28 = FUN_004cfab0();
        }
        FUN_00480f20(local_28);
        for (local_18 = 0; local_18 < local_10; local_18 = local_18 + 1) {
          FUN_004cfb40(param_2 + local_18);
          FUN_0047f3d0();
          piVar2 = (int *)FUN_004cfb40(param_2 + local_18);
          *piVar2 = param_2 + local_18;
        }
      }
      if (DAT_00a117ec == 0) {
        _free(DAT_00a0f830);
      }
    }
    else {
      local_10 = -1;
    }
  }
  return local_10;
}

