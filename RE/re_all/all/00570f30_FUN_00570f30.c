
undefined4 FUN_00570f30(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_2[0x221] == 1) {
    iVar1 = FUN_0056ef10(param_2);
    while (iVar1 == 0) {
      FUN_0056da20(0);
      iVar1 = FUN_0056ef10(param_2);
    }
  }
  *param_1 = param_2;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[8] = param_4;
  param_1[9] = 0;
  if (param_2[0x219] == 0) {
    iVar1 = FUN_0052db80(param_2 + 0x16,0,1,0);
    param_1[4] = iVar1;
    if (iVar1 == 0) {
      return 0xffffffff;
    }
  }
  if (*param_2 == 0) {
    iVar1 = FUN_005706d0(param_2);
    if (iVar1 != 0) {
      param_1[1] = iVar1;
      if ((*(uint *)(iVar1 + 0x38) & *(uint *)(iVar1 + 0x3c)) == 0xffffffff) {
        return 0;
      }
      uVar2 = FUN_0056e030(*(undefined4 *)(iVar1 + 0x30),
                           "..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xb4d);
      param_1[2] = uVar2;
      if (param_2[0x219] == 1) {
        if (param_2[0x21f] == 0) {
          FUN_00570180(*(int *)(iVar1 + 0x28) + param_2[0x10] + param_2[4],uVar2);
          return 0;
        }
        uVar2 = FUN_0056e030(*(undefined4 *)(iVar1 + 0x38),
                             "..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xb55);
        param_1[3] = uVar2;
        FUN_0056d420(uVar2,*(int *)(iVar1 + 0x28) + param_2[0x10] + param_2[4],
                     *(undefined4 *)(iVar1 + 0x30));
        FUN_0056e590(*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),
                     *(undefined4 *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x34),param_2 + 0x216);
        FUN_00570180(param_1[3],param_1[2]);
        FUN_0056e1d0(param_1[3]);
        param_1[3] = 0;
        return 0;
      }
      uVar2 = FUN_0056e030(*(undefined4 *)(iVar1 + 0x38),
                           "..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xb6b);
      param_1[3] = uVar2;
      iVar4 = *(uint *)(iVar1 + 0x28) + param_2[4];
      iVar3 = *(int *)(iVar1 + 0x2c) + param_2[5] + (uint)CARRY4(*(uint *)(iVar1 + 0x28),param_2[4])
      ;
      param_1[0xb] = iVar3;
      param_1[10] = iVar4;
      FUN_0052dc20(param_1[4],iVar4,iVar3,0);
      if (param_1[8] == 1) {
        FUN_0052dcb0(param_1[3],*(undefined4 *)(iVar1 + 0x38),1,param_1[4]);
        param_1[9] = 1;
        return 0;
      }
      FUN_0056e720(param_1[3],*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),
                   param_2 + 0x216,*(undefined4 *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x34));
      FUN_00570180(param_1[3],param_1[2]);
      FUN_0056e1d0(param_1[3]);
      param_1[3] = 0;
      return 0;
    }
    if (param_2[0x219] == 0) {
      FUN_0052dbe0(param_1[4]);
      param_1[4] = 0;
    }
  }
  else {
    iVar1 = FUN_00570590();
    if (iVar1 != 0) {
      param_1[1] = iVar1;
      if ((*(ushort *)((int)param_2 + 10) < 2) || (*(int *)(iVar1 + 0x28) == -1)) {
        return 0;
      }
      uVar2 = FUN_0056e030(*(undefined4 *)(iVar1 + 0x24),
                           "..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xaef);
      param_1[2] = uVar2;
      if (param_2[0x219] != 1) {
        uVar2 = FUN_0056e030(*(undefined4 *)(iVar1 + 0x28),
                             "..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xb14);
        param_1[3] = uVar2;
        iVar4 = *(int *)(iVar1 + 0x20) + param_2[4];
        param_1[10] = iVar4;
        param_1[0xb] = 0;
        FUN_0052dc20(param_1[4],iVar4,0,0);
        if (param_1[8] == 1) {
          FUN_0052dcb0(param_1[3],*(undefined4 *)(iVar1 + 0x28),1,param_1[4]);
          param_1[9] = 1;
          return 0;
        }
        if (*(ushort *)((int)param_2 + 10) < 5) {
          uVar6 = *(undefined4 *)(iVar1 + 0x28);
          uVar5 = param_1[3];
          uVar7 = 0xffffffff;
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = *(undefined4 *)(iVar1 + 0x24);
          uVar6 = *(undefined4 *)(iVar1 + 0x28);
          uVar5 = param_1[3];
          uVar7 = 0;
        }
        FUN_0056e720(uVar5,uVar6,0,param_2 + 0x216,uVar2,uVar7);
        FUN_00570180(param_1[3],param_1[2]);
        FUN_0056e1d0(param_1[3]);
        param_1[3] = 0;
        return 0;
      }
      if (param_2[0x21f] == 0) {
        FUN_00570180(param_2[0x10] + *(int *)(iVar1 + 0x20) + param_2[4],uVar2);
        return 0;
      }
      uVar2 = FUN_0056e030(*(undefined4 *)(iVar1 + 0x28),
                           "..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xaf7);
      param_1[3] = uVar2;
      FUN_0056d420(uVar2,param_2[0x10] + *(int *)(iVar1 + 0x20) + param_2[4],
                   *(undefined4 *)(iVar1 + 0x28));
      if (*(ushort *)((int)param_2 + 10) < 5) {
        iVar4 = *(int *)(iVar1 + 0x20) + param_2[4];
      }
      else {
        iVar4 = *(int *)(iVar1 + 0x24);
      }
      FUN_0056e590(*(undefined4 *)(iVar1 + 0x28),0,iVar4,0,param_2 + 0x216);
      FUN_00570180(param_1[3],param_1[2]);
      FUN_0056e1d0(param_1[3]);
      param_1[3] = 0;
      return 0;
    }
    if (param_2[0x219] == 0) {
      FUN_0052dbe0(param_1[4]);
      param_1[4] = 0;
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

