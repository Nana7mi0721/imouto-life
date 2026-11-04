
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff8 : 0x0056378c */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_00563700(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_ESI;
  int *piVar5;
  undefined2 *puVar6;
  int *unaff_EDI;
  int *piVar7;
  short local_8 [4];
  
  local_8[0] = 0;
  local_8[1] = 0;
  if (DAT_00aa6ffc != 0) {
    FUN_0056e1d0();
    DAT_00aa6ffc = 0;
    DAT_00aa7000 = 0;
  }
  iVar2 = (**(code **)(*unaff_EDI + 0x28))();
  iVar3 = (**(code **)(*unaff_EDI + 0x24))();
  if (((unaff_EDI == (int *)0x0) || (iVar3 != 0)) || (iVar2 != 0)) {
    unaff_ESI = 0;
    DAT_00aa7000 = 0x18;
    piVar7 = (int *)0x0;
  }
  else {
    DAT_00aa7000 = (int)unaff_EDI * 4 + 0x18;
    piVar5 = (int *)0x0;
    piVar7 = unaff_EDI;
    if (unaff_EDI != (int *)0x0) {
      do {
        iVar2 = (**(code **)(*unaff_EDI + 0x2c))();
        if ((local_8 == (short *)0x0) || (iVar2 != 0)) {
          DAT_00aa7000 = DAT_00aa7000 + 2;
        }
        else {
          iVar2 = 0;
          sVar1 = local_8[0];
          while (sVar1 != 0) {
            iVar2 = iVar2 + 1;
            sVar1 = local_8[iVar2];
          }
          DAT_00aa7000 = DAT_00aa7000 + 2 + iVar2 * 2;
          (*DAT_00aba1ac)(local_8);
        }
        piVar5 = (int *)((int)piVar5 + 1);
      } while (piVar5 < unaff_EDI);
    }
  }
  DAT_00aa6ffc = FUN_0056e030(DAT_00aa7000,
                              "..\\..\\..\\..\\Source\\Library\\Main\\DxInputString.cpp",0xe0);
  if (DAT_00aa6ffc == 0) {
    FUN_0056bca0(&DAT_007d6b48,DAT_00aa7000);
    DAT_00aa7000 = 0;
    return;
  }
  *(int **)(DAT_00aa6ffc + 8) = piVar7;
  *(undefined4 *)(DAT_00aa6ffc + 0xc) = unaff_ESI;
  iVar2 = (int)piVar7 * 4 + 0x18;
  piVar5 = (int *)0x0;
  if (piVar7 != (int *)0x0) {
    iVar3 = 0x18;
    do {
      *(int *)(iVar3 + DAT_00aa6ffc) = iVar2;
      puVar6 = (undefined2 *)(*(int *)(iVar3 + DAT_00aa6ffc) + DAT_00aa6ffc);
      iVar4 = (**(code **)(*unaff_EDI + 0x2c))();
      if ((local_8 == (short *)0x0) || (iVar4 != 0)) {
        *puVar6 = 0;
        iVar2 = iVar2 + 2;
      }
      else {
        FUN_0056cf10(puVar6,local_8);
        iVar4 = 0;
        sVar1 = local_8[0];
        while (sVar1 != 0) {
          iVar4 = iVar4 + 1;
          sVar1 = local_8[iVar4];
        }
        iVar2 = iVar2 + 2 + iVar4 * 2;
        (*DAT_00aba1ac)(local_8);
      }
      piVar5 = (int *)((int)piVar5 + 1);
      iVar3 = iVar3 + 4;
    } while (piVar5 < piVar7);
  }
  return;
}

