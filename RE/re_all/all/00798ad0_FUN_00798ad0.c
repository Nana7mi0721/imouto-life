
int FUN_00798ad0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                undefined4 param_7,int param_8,int param_9)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  int local_64;
  short local_60 [48];
  
  iVar6 = param_5;
  iVar2 = param_4;
  iVar8 = param_2;
  iVar5 = param_1;
  if (((-1 < param_6) && (param_6 < 2)) &&
     (((param_6 == 0 && ((param_3 != 0 && (param_2 != 0)))) ||
      (param_5 % (*(int *)(param_1 + 0xc) / 400) == 0)))) {
    if ((param_3 == 0) || (param_2 == 0)) {
      iVar4 = 0;
      iVar8 = FUN_00798e20(param_1,0,0,param_4,param_5,0);
      if (iVar8 < 0) {
        return iVar8;
      }
      do {
        iVar4 = iVar4 + iVar8;
        if (iVar6 <= iVar4) {
          *(int *)(iVar5 + 0x44) = iVar4;
          return iVar4;
        }
        iVar8 = FUN_00798e20(iVar5,0,0,iVar2 + *(int *)(iVar5 + 8) * iVar4 * 4,iVar6 - iVar4,0);
      } while (-1 < iVar8);
      return iVar8;
    }
    if (-1 < param_3) {
      param_2 = FUN_00798e00(param_2);
      uVar1 = FUN_00799a10(iVar8);
      iVar2 = FUN_00798510(iVar8,*(undefined4 *)(iVar5 + 0xc));
      uVar3 = FUN_00799a60(iVar8);
      param_8 = FUN_007985c0(iVar8,param_3,param_7,&param_1,0,local_60,&local_64,param_8);
      if (param_8 < 0) {
        return param_8;
      }
      iVar8 = iVar8 + local_64;
      if (param_6 != 0) {
        if (((iVar6 < iVar2) || (param_2 == 0x3ea)) || (*(int *)(iVar5 + 0x34) == 0x3ea)) {
          iVar5 = FUN_00798ad0(iVar5,0,0,param_4,iVar6,0,0,0,param_9);
          return iVar5;
        }
        param_3 = *(undefined4 *)(iVar5 + 0x44);
        iVar6 = iVar6 - iVar2;
        if ((iVar6 != 0) && (iVar4 = FUN_00798ad0(iVar5,0,0,param_4,iVar6,0,0,0,param_9), iVar4 < 0)
           ) {
          *(int *)(iVar5 + 0x44) = param_3;
          return iVar4;
        }
        *(int *)(iVar5 + 0x34) = param_2;
        *(undefined4 *)(iVar5 + 0x30) = uVar1;
        *(undefined4 *)(iVar5 + 0x2c) = uVar3;
        *(int *)(iVar5 + 0x3c) = iVar2;
        iVar8 = FUN_00798e20(iVar5,iVar8,(int)local_60[0],param_4 + *(int *)(iVar5 + 8) * iVar6 * 4,
                             iVar2,1);
        if (iVar8 < 0) {
          return iVar8;
        }
        *(int *)(iVar5 + 0x44) = param_5;
        return param_5;
      }
      if (iVar6 < param_8 * iVar2) {
        return -2;
      }
      *(int *)(iVar5 + 0x3c) = iVar2;
      *(int *)(iVar5 + 0x34) = param_2;
      *(undefined4 *)(iVar5 + 0x30) = uVar1;
      iVar2 = 0;
      *(undefined4 *)(iVar5 + 0x2c) = uVar3;
      param_3 = 0;
      if (0 < param_8) {
        psVar7 = local_60;
        do {
          iVar6 = FUN_00798e20(iVar5,iVar8,(int)*psVar7,param_4 + *(int *)(iVar5 + 8) * iVar2 * 4,
                               param_5 - iVar2,0);
          if (iVar6 < 0) {
            return iVar6;
          }
          iVar2 = iVar2 + iVar6;
          iVar8 = iVar8 + *psVar7;
          param_3 = param_3 + 1;
          psVar7 = psVar7 + 1;
        } while (param_3 < param_8);
      }
      *(int *)(iVar5 + 0x44) = iVar2;
      if (param_9 == 0) {
        *(undefined4 *)(iVar5 + 0x4c) = 0;
        *(undefined4 *)(iVar5 + 0x48) = 0;
        return iVar2;
      }
      FUN_007981c0(param_4,iVar2,*(undefined4 *)(iVar5 + 8),iVar5 + 0x48);
      return iVar2;
    }
  }
  return -1;
}

