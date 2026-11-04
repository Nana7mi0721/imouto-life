
undefined4
FUN_0053f880(int param_1,int param_2,short *param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int param_8)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if ((((param_3 != (short *)0x0) && (*param_3 != 0)) && (param_4 != 0)) && (DAT_00a37fd0 == 0)) {
    if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
      FUN_0050e770();
    }
    iVar2 = FUN_0052eda0(param_6);
    if (iVar2 == 0) {
      FUN_0056bb10(&DAT_007d5cdc);
      return 0xffffffff;
    }
    if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
      FUN_005198b0();
    }
    if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(int *)(iVar2 + 0x93628) != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
      if (DAT_00ca39f4 == 0) {
        if (*(int *)(iVar2 + 0x93628) == 0) {
          uVar4 = FUN_0053ea50(param_1,param_2,param_3,param_4,param_5,param_7,param_8);
          return uVar4;
        }
        uVar4 = FUN_0053e600(param_1,param_2,(float)param_1,(float)param_2,1,param_3,param_4,param_5
                             ,param_7,param_8);
        return uVar4;
      }
    }
    if (param_8 == 0) {
      local_c = param_2 - (uint)(*(ushort *)(iVar2 + 0x93166) >> 1);
      local_10 = param_1;
      local_8 = DAT_00a3819c;
      iVar3 = FUN_00536eb0(param_6);
      local_4 = iVar3 + 3 + local_c;
      if (param_1 < DAT_00a3819c) {
        param_2 = local_c + (uint)(*(ushort *)(iVar2 + 0x93166) >> 1);
        goto LAB_0053fa65;
      }
    }
    else {
      local_10 = param_1 + (uint)(*(ushort *)(iVar2 + 0x93166) >> 1);
      local_c = param_2;
      iVar3 = FUN_00536eb0(param_6);
      local_8 = iVar3 + 3 + local_10;
      local_4 = DAT_00a381a0;
      if (local_10 < DAT_00a3819c) {
        param_1 = local_10 - (uint)(*(ushort *)(iVar2 + 0x93166) >> 1);
LAB_0053fa65:
        if (-1 < (int)((local_8 - DAT_00a3819c) - 1U & (local_4 - DAT_00a381a0) - 1U &
                       (DAT_00a38198 - local_c) - 1U & (DAT_00a38194 - local_10) - 1U)) {
          if (local_10 < DAT_00a38194) {
            local_10 = DAT_00a38194;
          }
          if (local_8 < DAT_00a38194) {
            local_8 = DAT_00a38194;
          }
          if (DAT_00a3819c < local_10) {
            local_10 = DAT_00a3819c;
          }
          if (DAT_00a3819c < local_8) {
            local_8 = DAT_00a3819c;
          }
          if (local_c < DAT_00a38198) {
            local_c = DAT_00a38198;
          }
          if (local_4 < DAT_00a38198) {
            local_4 = DAT_00a38198;
          }
          if (DAT_00a381a0 < local_c) {
            local_c = DAT_00a381a0;
          }
          if (DAT_00a381a0 < local_4) {
            local_4 = DAT_00a381a0;
          }
        }
        if (DAT_00ca39f4 != 0) {
          FUN_0057b170(local_10,local_c,local_8,local_4);
        }
        if (bVar1) {
          FUN_00519580();
          uVar4 = FUN_0053e600(param_1,param_2,(float)param_1,(float)param_2,1,param_3,param_4,
                               param_5,param_7,param_8);
          FUN_00519650();
        }
        else if (*(int *)(iVar2 + 0x93628) == 0) {
          uVar4 = FUN_0053ea50(param_1,param_2,param_3,param_4,param_5,param_7,param_8);
        }
        else {
          uVar4 = FUN_0053e600(param_1,param_2,(float)param_1,(float)param_2,1,param_3,param_4,
                               param_5,param_7,param_8);
        }
        if (DAT_00ca39f4 != 0) {
          FUN_0057ae10(local_10,local_c,local_8,local_4);
        }
        return uVar4;
      }
    }
  }
  return 0;
}

