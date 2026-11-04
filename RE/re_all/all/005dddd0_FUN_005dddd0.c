
undefined4 FUN_005dddd0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00514e10(param_1,&DAT_00a38194);
  if (*param_1 != param_1[2]) {
    if (param_1[1] != param_1[3]) {
      iVar1 = param_1[3] - param_1[1];
      iVar3 = param_1[2] - *param_1;
      local_10 = iVar3;
      iVar2 = (**(code **)(*DAT_00f3a14c + 0x4c))(DAT_00f3a14c,0,&local_20,param_1,0);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      local_c = DAT_00ca39d8 - iVar3;
      local_14 = (undefined1 *)(param_1[1] * DAT_00ca39d8 + *param_1 + DAT_00ca39d4);
      local_18 = local_1c;
      param_1 = (int *)iVar1;
      if (DAT_00ddb594 == 0x15) {
        local_8 = local_20 + iVar3 * -4;
        puVar4 = local_14;
        do {
          iVar1 = local_10;
          do {
            *(undefined1 *)(local_1c + 3) = *puVar4;
            puVar4 = puVar4 + 1;
            local_1c = local_1c + 4;
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
          local_1c = local_1c + local_8;
          puVar4 = puVar4 + local_c;
          param_1 = (int *)((int)param_1 + -1);
        } while (param_1 != (int *)0x0);
      }
      else if (DAT_00ddb594 - 0x19U < 2) {
        local_8 = local_20 + iVar3 * -2;
        puVar4 = local_14;
        do {
          iVar1 = local_10;
          do {
            *(undefined1 *)(local_1c + 1) = *puVar4;
            puVar4 = puVar4 + 1;
            local_1c = local_1c + 2;
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
          local_1c = local_1c + local_8;
          puVar4 = puVar4 + local_c;
          param_1 = (int *)((int)param_1 + -1);
        } while (param_1 != (int *)0x0);
      }
      (**(code **)(*DAT_00f3a14c + 0x50))(DAT_00f3a14c,0);
    }
  }
  return 0;
}

