
undefined4 FUN_006abfd0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar5 = *(int *)(param_1 + 0x1c);
  if (iVar5 == 0) {
    return 0xffffff7f;
  }
  iVar1 = FUN_00797830(param_2,8);
  iVar1 = iVar1 + 1;
  *(int *)(iVar5 + 0x18) = iVar1;
  if (0 < iVar1) {
    iVar6 = 0;
    if (0 < iVar1) {
      piVar7 = (int *)(iVar5 + 0x720);
      do {
        iVar1 = FUN_006b0640(param_2);
        *piVar7 = iVar1;
        if (iVar1 == 0) goto LAB_006ac253;
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar6 < *(int *)(iVar5 + 0x18));
    }
    iVar1 = FUN_00797830(param_2,6);
    iVar1 = iVar1 + 1;
    if (0 < iVar1) {
      iVar6 = 0;
      if (0 < iVar1) {
        do {
          iVar2 = FUN_00797830(param_2,0x10);
          if ((iVar2 < 0) || (0 < iVar2)) goto LAB_006ac253;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar1);
      }
      iVar1 = FUN_00797830(param_2,6);
      iVar1 = iVar1 + 1;
      *(int *)(iVar5 + 0x10) = iVar1;
      if (0 < iVar1) {
        iVar6 = 0;
        if (0 < iVar1) {
          piVar7 = (int *)(iVar5 + 0x420);
          do {
            iVar1 = FUN_00797830(param_2,0x10);
            piVar7[-0x40] = iVar1;
            if ((iVar1 < 0) || (1 < iVar1)) goto LAB_006ac253;
            iVar1 = (**(code **)((&PTR_DAT_008298c4)[iVar1] + 4))(param_1,param_2);
            *piVar7 = iVar1;
            if (iVar1 == 0) goto LAB_006ac253;
            iVar6 = iVar6 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar6 < *(int *)(iVar5 + 0x10));
        }
        iVar1 = FUN_00797830(param_2,6);
        iVar1 = iVar1 + 1;
        *(int *)(iVar5 + 0x14) = iVar1;
        if (0 < iVar1) {
          iVar6 = 0;
          if (0 < iVar1) {
            piVar7 = (int *)(iVar5 + 0x620);
            do {
              iVar1 = FUN_00797830(param_2,0x10);
              piVar7[-0x40] = iVar1;
              if ((iVar1 < 0) || (2 < iVar1)) goto LAB_006ac253;
              iVar1 = (**(code **)((&PTR_DAT_008298cc)[iVar1] + 4))(param_1,param_2);
              *piVar7 = iVar1;
              if (iVar1 == 0) goto LAB_006ac253;
              iVar6 = iVar6 + 1;
              piVar7 = piVar7 + 1;
            } while (iVar6 < *(int *)(iVar5 + 0x14));
          }
          iVar1 = FUN_00797830(param_2,6);
          iVar1 = iVar1 + 1;
          *(int *)(iVar5 + 0xc) = iVar1;
          if (0 < iVar1) {
            iVar6 = 0;
            if (0 < iVar1) {
              piVar7 = (int *)(iVar5 + 0x220);
              do {
                iVar1 = FUN_00797830(param_2,0x10);
                piVar7[-0x40] = iVar1;
                if ((iVar1 < 0) || (0 < iVar1)) goto LAB_006ac253;
                iVar1 = (**(code **)((&PTR_PTR_008298d8)[iVar1] + 4))(param_1,param_2);
                *piVar7 = iVar1;
                if (iVar1 == 0) goto LAB_006ac253;
                iVar6 = iVar6 + 1;
                piVar7 = piVar7 + 1;
              } while (iVar6 < *(int *)(iVar5 + 0xc));
            }
            iVar1 = FUN_00797830(param_2,6);
            iVar1 = iVar1 + 1;
            *(int *)(iVar5 + 8) = iVar1;
            if (0 < iVar1) {
              iVar6 = 0;
              if (0 < iVar1) {
                piVar7 = (int *)(iVar5 + 0x20);
                do {
                  pvVar3 = _calloc(1,0x10);
                  *piVar7 = (int)pvVar3;
                  uVar4 = FUN_00797830(param_2,1);
                  *(undefined4 *)*piVar7 = uVar4;
                  uVar4 = FUN_00797830(param_2,0x10);
                  *(undefined4 *)(*piVar7 + 4) = uVar4;
                  uVar4 = FUN_00797830(param_2,0x10);
                  *(undefined4 *)(*piVar7 + 8) = uVar4;
                  uVar4 = FUN_00797830(param_2,8);
                  *(undefined4 *)(*piVar7 + 0xc) = uVar4;
                  iVar1 = *piVar7;
                  if ((((0 < *(int *)(iVar1 + 4)) || (0 < *(int *)(iVar1 + 8))) ||
                      (*(int *)(iVar5 + 0xc) <= *(int *)(iVar1 + 0xc))) ||
                     (*(int *)(iVar1 + 0xc) < 0)) goto LAB_006ac253;
                  iVar6 = iVar6 + 1;
                  piVar7 = piVar7 + 1;
                } while (iVar6 < *(int *)(iVar5 + 8));
              }
              iVar5 = FUN_00797830(param_2,1);
              if (iVar5 == 1) {
                return 0;
              }
            }
          }
        }
      }
    }
  }
LAB_006ac253:
  FUN_006abab0(param_1);
  return 0xffffff7b;
}

