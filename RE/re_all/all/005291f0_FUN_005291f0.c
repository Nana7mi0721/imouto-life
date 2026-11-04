
undefined4 FUN_005291f0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_804;
  undefined1 local_800 [2048];
  
  if (((param_3 == 0) && (DAT_00a21078 == 0)) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (*(int *)(param_1 + 0x128) == 0) {
    iVar2 = FUN_005809a0(1,param_3,0xffffffff);
    *(int *)(param_1 + 300) = iVar2;
    if (iVar2 < 0) {
      return 0xffffffff;
    }
LAB_00529275:
    if (param_3 == 0) goto LAB_0052927d;
  }
  else {
    iVar2 = FUN_00580560(*(undefined4 *)(param_1 + 300));
    if (0 < iVar2) {
      return 0xffffffff;
    }
    if (param_3 != 0) {
      FUN_00580610(*(undefined4 *)(param_1 + 300),0xffffffff);
      goto LAB_00529275;
    }
LAB_0052927d:
    if (param_2 != 0) {
      local_804 = 0;
      FUN_0057fac0(0,&local_804,param_1,400);
      if (*(int *)(param_1 + 0x134) != 0) {
        FUN_0052d510(*(int *)(param_1 + 0x134),local_800,0x800,0);
        FUN_0057fb30(0,&local_804,local_800);
      }
      if (*(int *)(param_1 + 0x158) != 0) {
        FUN_0057fac0(0,&local_804,*(int *)(param_1 + 0x158),0x440);
      }
      if (*(int *)(param_1 + 0x15c) != 0) {
        FUN_0057fac0(0,&local_804,*(int *)(param_1 + 0x15c),0x440);
      }
      puVar3 = (undefined4 *)FUN_0057fa80(local_804);
      if (puVar3 != (undefined4 *)0x0) {
        puVar1 = puVar3 + 4;
        puVar3[3] = &LAB_00529130;
        local_804 = 0;
        FUN_0057fac0(puVar1,&local_804,param_1,400);
        if (*(int *)(param_1 + 0x134) != 0) {
          FUN_0057fb30(puVar1,&local_804,local_800);
        }
        if (*(int *)(param_1 + 0x158) != 0) {
          FUN_0057fac0(puVar1,&local_804,*(int *)(param_1 + 0x158),0x440);
        }
        if (*(int *)(param_1 + 0x15c) != 0) {
          FUN_0057fac0(puVar1,&local_804,*(int *)(param_1 + 0x15c),0x440);
        }
        iVar2 = FUN_00580290(puVar3);
        if (iVar2 < 0) {
          FUN_0056e1d0(puVar3);
          goto LAB_0052941c;
        }
        FUN_00580610(*(undefined4 *)(param_1 + 300),*puVar3);
        goto LAB_005293e3;
      }
      goto LAB_0052941c;
    }
  }
  iVar2 = FUN_00528f40();
  if (-1 < iVar2) {
LAB_005293e3:
    if (param_3 != 0) {
      FUN_00580f70(*(undefined4 *)(param_1 + 300));
    }
    if (*(int *)(param_1 + 0x128) == 0) {
      return *(undefined4 *)(param_1 + 300);
    }
    return 0;
  }
LAB_0052941c:
  if (param_3 != 0) {
    FUN_00580f70(*(undefined4 *)(param_1 + 300));
  }
  if (*(int *)(param_1 + 0x128) == 0) {
    FUN_00580b80(*(undefined4 *)(param_1 + 300));
    *(undefined4 *)(param_1 + 300) = 0xffffffff;
  }
  return 0xffffffff;
}

