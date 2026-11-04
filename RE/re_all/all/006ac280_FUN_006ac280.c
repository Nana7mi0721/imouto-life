
undefined4 FUN_006ac280(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int local_4;
  
  piVar2 = param_1;
  if (param_1 == (int *)0x0) {
    iVar3 = 0;
LAB_006ac2a8:
    param_1 = (int *)0x0;
    local_4 = 0;
  }
  else {
    iVar3 = param_1[0x10];
    if (iVar3 == 0) goto LAB_006ac2a8;
    param_1 = *(int **)(iVar3 + 0x68);
    local_4 = *(int *)(iVar3 + 4);
    if (local_4 != 0) {
      iVar7 = *(int *)(local_4 + 0x1c);
      goto LAB_006ac2bf;
    }
  }
  iVar7 = 0;
LAB_006ac2bf:
  if (piVar2 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = piVar2 + 1;
  }
  if ((((iVar3 != 0) && (param_1 != (int *)0x0)) && (local_4 != 0)) &&
     ((iVar7 != 0 && (piVar6 != (int *)0x0)))) {
    FUN_006ac690(piVar2);
    FUN_007976d0(piVar6,*param_2,param_2[1]);
    iVar3 = FUN_00797830(piVar6,1);
    if (iVar3 != 0) {
      return 0xffffff79;
    }
    iVar3 = FUN_00797830(piVar6,*(undefined4 *)((int)param_1 + 0x2c));
    if (iVar3 != -1) {
      piVar2[10] = iVar3;
      piVar1 = *(int **)(iVar7 + 0x20 + iVar3 * 4);
      if (piVar1 != (int *)0x0) {
        iVar4 = *piVar1;
        piVar2[7] = iVar4;
        if (iVar4 == 0) {
          piVar2[6] = 0;
          piVar2[8] = 0;
        }
        else {
          iVar4 = FUN_00797830(piVar6,1);
          piVar2[6] = iVar4;
          iVar4 = FUN_00797830(piVar6,1);
          piVar2[8] = iVar4;
          if (iVar4 == -1) {
            return 0xffffff78;
          }
        }
        piVar2[0xc] = param_2[4];
        piVar2[0xd] = param_2[5];
        piVar2[0xe] = param_2[6];
        piVar2[0xf] = param_2[7];
        piVar2[0xb] = param_2[3];
        piVar2[9] = *(int *)(iVar7 + piVar2[7] * 4);
        iVar4 = FUN_006ac620(piVar2,*(int *)(local_4 + 4) << 2);
        *piVar2 = iVar4;
        iVar4 = 0;
        if (0 < *(int *)(local_4 + 4)) {
          do {
            uVar5 = FUN_006ac620(piVar2,piVar2[9] << 2);
            *(undefined4 *)(*piVar2 + iVar4 * 4) = uVar5;
            iVar4 = iVar4 + 1;
          } while (iVar4 < *(int *)(local_4 + 4));
        }
        iVar3 = *(int *)(*(int *)(iVar7 + 0x20 + iVar3 * 4) + 0xc);
        uVar5 = (**(code **)((&PTR_PTR_008298d8)[*(int *)(iVar7 + 0x120 + iVar3 * 4)] + 0x10))
                          (piVar2,*(undefined4 *)(iVar7 + 0x220 + iVar3 * 4));
        return uVar5;
      }
    }
  }
  return 0xffffff78;
}

