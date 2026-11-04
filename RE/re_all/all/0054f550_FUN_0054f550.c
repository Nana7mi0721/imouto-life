
undefined4 FUN_0054f550(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  
  if (DAT_00a798d8 == 0) {
    iVar7 = 0;
    if (0 < param_1[2]) {
      do {
        FUN_0054f4e0();
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_1[2]);
LAB_0054f585:
      iVar5 = DAT_00a82788;
      goto LAB_0054f58b;
    }
  }
  else {
    iVar7 = 0;
    if (param_1[2] < 1) goto LAB_0054f585;
    piVar6 = param_1 + 3;
    iVar5 = DAT_00a82788;
    do {
      iVar3 = DAT_00a82770;
      iVar2 = 0;
      if (0 < iVar5) {
        piVar4 = &DAT_00a82790;
        do {
          if (piVar6[1] == *piVar4) break;
          iVar2 = iVar2 + 1;
          piVar4 = piVar4 + 4;
        } while (iVar2 < iVar5);
      }
      if (iVar2 == iVar5) {
        if (DAT_00a81fec == 0x78) {
          DAT_00a82770 = DAT_00a82770 + 1;
          if (DAT_00a82770 == 0x78) {
            DAT_00a82770 = 0;
          }
        }
        else {
          iVar3 = DAT_00a82770 + DAT_00a81fec;
          if (0x77 < iVar3) {
            iVar3 = iVar3 + -0x78;
          }
          DAT_00a81fec = DAT_00a81fec + 1;
        }
        (&DAT_00a81ff0)[iVar3 * 4] = *piVar6;
        (&DAT_00a81ff4)[iVar3 * 4] = piVar6[1];
        *(int *)(&DAT_00a81ff8 + iVar3 * 0x10) = piVar6[2];
        *(int *)(&DAT_00a81ffc + iVar3 * 0x10) = piVar6[3];
        iVar5 = DAT_00a82788;
      }
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 4;
    } while (iVar7 < param_1[2]);
LAB_0054f58b:
    if ((0 < DAT_00a798d8) && (iVar7 = 0, 0 < iVar5)) {
      puVar8 = &DAT_00a8278c;
      do {
        iVar3 = DAT_00a82770;
        iVar2 = param_1[2];
        iVar1 = 0;
        if (0 < iVar2) {
          piVar6 = param_1;
          do {
            piVar6 = piVar6 + 4;
            if (puVar8[1] == *piVar6) break;
            iVar1 = iVar1 + 1;
          } while (iVar1 < iVar2);
        }
        if (iVar1 == iVar2) {
          if (DAT_00a81fec == 0x78) {
            DAT_00a82770 = DAT_00a82770 + 1;
            if (DAT_00a82770 == 0x78) {
              DAT_00a82770 = 0;
            }
          }
          else {
            iVar3 = DAT_00a82770 + DAT_00a81fec;
            if (0x77 < iVar3) {
              iVar3 = iVar3 + -0x78;
            }
            DAT_00a81fec = DAT_00a81fec + 1;
          }
          (&DAT_00a81ff0)[iVar3 * 4] = *puVar8;
          (&DAT_00a81ff4)[iVar3 * 4] = puVar8[1];
          *(undefined4 *)(&DAT_00a81ff8 + iVar3 * 0x10) = puVar8[2];
          *(undefined4 *)(&DAT_00a81ffc + iVar3 * 0x10) = puVar8[3];
          iVar5 = DAT_00a82788;
        }
        iVar7 = iVar7 + 1;
        puVar8 = puVar8 + 4;
      } while (iVar7 < iVar5);
    }
    iVar7 = DAT_00a81860;
    if (DAT_00a798d8 == 0x78) {
      DAT_00a81860 = DAT_00a81860 + 1;
      if (DAT_00a81860 == 0x78) {
        DAT_00a81860 = 0;
      }
      goto LAB_0054f752;
    }
  }
  iVar7 = DAT_00a81860 + DAT_00a798d8;
  if (0x77 < iVar7) {
    iVar7 = iVar7 + -0x78;
  }
  DAT_00a798d8 = DAT_00a798d8 + 1;
LAB_0054f752:
  piVar6 = param_1;
  piVar4 = (int *)(&DAT_00a798e0 + iVar7 * 0x110);
  for (iVar5 = 0x44; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar4 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar4 = piVar4 + 1;
  }
  piVar6 = param_1;
  piVar4 = &DAT_00a82780;
  for (iVar7 = 0x44; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar4 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar4 = piVar4 + 1;
  }
  iVar7 = param_1[2];
  if (iVar7 == 0) {
    DAT_00a82774 = 0xffffffff;
    DAT_00a8277c = 0xffffffff;
    DAT_00a82778 = 0xffffffff;
    return 0;
  }
  iVar5 = 0;
  piVar6 = param_1;
  if (0 < iVar7) {
    do {
      if ((DAT_00a82774 == piVar6[3]) && (DAT_00a82778 == piVar6[4])) {
        DAT_00a8277c = iVar5;
        break;
      }
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + 4;
    } while (iVar5 < iVar7);
  }
  if (iVar5 == param_1[2]) {
    DAT_00a82774 = param_1[3];
    DAT_00a82778 = param_1[4];
    DAT_00a8277c = 0;
  }
  return 0;
}

