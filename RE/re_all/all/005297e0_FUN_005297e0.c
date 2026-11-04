
undefined4 FUN_005297e0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  iVar2 = param_1;
  iVar6 = *(int *)(param_1 + 0x160);
  if (iVar6 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x130) = 0xffffffff;
  if (*(int *)(param_1 + 0x128) == 0) {
    FUN_0056d380(*(undefined4 *)(param_1 + 0x180),0,iVar6 * 4);
    iVar6 = param_3;
    iVar5 = 0;
    if (0 < *(int *)(iVar2 + 0x160)) {
      do {
        uVar3 = FUN_005809a0(1,iVar6,0xffffffff);
        *(undefined4 *)(*(int *)(iVar2 + 0x180) + iVar5 * 4) = uVar3;
        if (*(int *)(*(int *)(iVar2 + 0x180) + iVar5 * 4) < 0) goto LAB_00529acb;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(iVar2 + 0x160));
    }
    iVar5 = FUN_005809a0(1,iVar6,0xffffffff);
    *(int *)(iVar2 + 0x130) = iVar5;
    if (iVar5 < 0) goto LAB_00529acb;
  }
  else {
    iVar5 = 0;
    if (0 < iVar6) {
      do {
        iVar6 = FUN_00580560(*(undefined4 *)(*(int *)(iVar2 + 0x180) + iVar5 * 4));
        if (0 < iVar6) {
          return 0xffffffff;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(iVar2 + 0x160));
    }
    iVar6 = param_3;
    if (param_3 != 0) {
      FUN_00580610(*(undefined4 *)(iVar2 + 0x130),0xffffffff);
      iVar5 = 0;
      if (0 < *(int *)(iVar2 + 0x160)) {
        do {
          FUN_00580610(*(undefined4 *)(*(int *)(iVar2 + 0x180) + iVar5 * 4),0xffffffff);
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(iVar2 + 0x160));
      }
    }
  }
  if (param_2 == 0) {
    iVar5 = FUN_00529470(0);
    if (-1 < iVar5) {
      if (*(int *)(iVar2 + 0x128) == 0) {
        FUN_00580b80(*(undefined4 *)(iVar2 + 0x130));
      }
LAB_00529b6c:
      if (iVar6 != 0) {
        FUN_00580f70(*(undefined4 *)(iVar2 + 0x130));
        iVar6 = 0;
        if (0 < *(int *)(iVar2 + 0x160)) {
          do {
            FUN_00580f70(*(undefined4 *)(*(int *)(iVar2 + 0x180) + iVar6 * 4));
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(int *)(iVar2 + 0x160));
        }
      }
      return 0;
    }
  }
  else {
    param_1 = 0;
    FUN_0057fac0(0,&param_1,iVar2,400);
    FUN_0057fac0(0,&param_1,*(undefined4 *)(iVar2 + 0x180),*(int *)(iVar2 + 0x160) * 4);
    if (*(int *)(iVar2 + 0x134) != 0) {
      FUN_0057fb30(0,&param_1,*(int *)(iVar2 + 0x134));
    }
    if (*(int *)(iVar2 + 0x158) != 0) {
      FUN_0057fac0(0,&param_1,*(int *)(iVar2 + 0x158),0x440);
    }
    if (*(int *)(iVar2 + 0x15c) != 0) {
      FUN_0057fac0(0,&param_1,*(int *)(iVar2 + 0x15c),0x440);
    }
    puVar4 = (undefined4 *)FUN_0057fa80(param_1);
    if (puVar4 != (undefined4 *)0x0) {
      puVar1 = puVar4 + 4;
      puVar4[3] = &LAB_005296c0;
      param_1 = 0;
      FUN_0057fac0(puVar1,&param_1,iVar2,400);
      FUN_0057fac0(puVar1,&param_1,*(undefined4 *)(iVar2 + 0x180),*(int *)(iVar2 + 0x160) * 4);
      if (*(int *)(iVar2 + 0x134) != 0) {
        FUN_0057fb30(puVar1,&param_1,*(int *)(iVar2 + 0x134));
      }
      if (*(int *)(iVar2 + 0x158) != 0) {
        FUN_0057fac0(puVar1,&param_1,*(int *)(iVar2 + 0x158),0x440);
      }
      if (*(int *)(iVar2 + 0x15c) != 0) {
        FUN_0057fac0(puVar1,&param_1,*(int *)(iVar2 + 0x15c),0x440);
      }
      iVar5 = FUN_00580290(puVar4);
      if (-1 < iVar5) {
        if (0 < *(int *)(iVar2 + 0x160)) {
          iVar5 = 0;
          do {
            FUN_00580610(*(undefined4 *)(*(int *)(iVar2 + 0x180) + iVar5 * 4),*puVar4);
            iVar5 = iVar5 + 1;
          } while (iVar5 < *(int *)(iVar2 + 0x160));
        }
        FUN_00580610(*(undefined4 *)(iVar2 + 0x130),*puVar4);
        goto LAB_00529b6c;
      }
      FUN_0056e1d0(puVar4);
    }
  }
LAB_00529acb:
  if (iVar6 != 0) {
    FUN_00580f70(*(undefined4 *)(iVar2 + 0x130));
    iVar6 = 0;
    if (0 < *(int *)(iVar2 + 0x160)) {
      do {
        FUN_00580f70(*(undefined4 *)(*(int *)(iVar2 + 0x180) + iVar6 * 4));
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(iVar2 + 0x160));
    }
  }
  if (*(int *)(iVar2 + 0x128) == 0) {
    iVar6 = 0;
    if (0 < *(int *)(iVar2 + 0x160)) {
      do {
        FUN_00580b80(*(undefined4 *)(*(int *)(iVar2 + 0x180) + iVar6 * 4));
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(iVar2 + 0x160));
    }
    FUN_00580b80(*(undefined4 *)(iVar2 + 0x130));
  }
  return 0xffffffff;
}

