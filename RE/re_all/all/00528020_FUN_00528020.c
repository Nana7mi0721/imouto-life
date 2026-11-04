
undefined4
FUN_00528020(uint *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,undefined4 param_9,int param_10,float param_11,int param_12,
            float param_13,undefined4 *param_14,undefined4 param_15,int param_16,undefined4 param_17
            )

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_18;
  int local_14;
  float local_c;
  float local_4;
  
  iVar3 = param_4;
  if (param_2 == 0) {
    iVar4 = FUN_005245d0(param_1,0,param_3,param_4,param_5,param_15,param_17);
    iVar3 = param_12;
    if (-1 < iVar4) {
      if (param_16 == 1) {
        local_14 = (param_7 + -1) * param_10;
        local_c = param_11 * (float)(param_7 + -1);
        iVar4 = -param_10;
        fVar1 = -param_11;
      }
      else {
        local_c = 0.0;
        local_14 = 0;
        iVar4 = param_10;
        fVar1 = param_11;
      }
      iVar9 = 0;
      local_18 = 0;
      if (0 < param_6) {
        iVar8 = 0;
        fVar2 = param_13;
        do {
          if (param_8 <= local_18) {
            return 0;
          }
          param_2 = 0;
          if (iVar9 < param_6) {
            iVar10 = local_14;
            do {
              if (param_7 <= param_2) break;
              local_4 = (float)param_2 * fVar1 + local_c;
              iVar5 = FUN_00527c20(param_14[iVar9],param_9,iVar10,local_4,iVar8,
                                   fVar2 * (float)local_18,param_10,param_11,iVar3,fVar2,param_3,
                                   param_17);
              if (iVar5 < 0) {
                FUN_0056bb10(&DAT_007d5838);
                return 0xffffffff;
              }
              param_2 = param_2 + 1;
              iVar10 = iVar10 + iVar4;
              iVar9 = iVar9 + 1;
              fVar2 = param_13;
            } while (iVar9 < param_6);
          }
          local_18 = local_18 + 1;
          iVar8 = iVar8 + iVar3;
        } while (iVar9 < param_6);
      }
      return 0;
    }
  }
  else {
    FUN_00544840(param_4);
    iVar4 = param_5;
    if (param_5 != 0) {
      FUN_00544840(param_5);
    }
    iVar8 = FUN_00515880(*param_14,&local_4,&param_2);
    iVar9 = param_8;
    if ((((iVar8 != -1) && (param_7 * param_10 <= *(int *)(iVar3 + 0x428))) &&
        (param_8 * param_12 <= *(int *)(iVar3 + 0x42c))) &&
       ((iVar4 == 0 ||
        ((*(int *)(iVar4 + 0x428) == *(int *)(iVar3 + 0x428) &&
         (*(int *)(iVar4 + 0x42c) == *(int *)(iVar3 + 0x42c))))))) {
      if (param_1[0x1d] == 1) {
        uVar6 = FUN_00540f50(iVar3,0,0);
        *param_1 = uVar6 & 0xffffff;
      }
      uVar7 = FUN_00523ed0(iVar3,iVar4,param_6,param_7,iVar9,param_9,param_10,param_11,param_12,
                           param_13,param_14,param_16,param_1[0x1b] == 0,param_17);
      return uVar7;
    }
  }
  return 0xffffffff;
}

