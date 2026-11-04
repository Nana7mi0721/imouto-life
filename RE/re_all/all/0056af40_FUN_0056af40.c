
undefined4 FUN_0056af40(void)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined2 local_4c;
  undefined2 local_4a;
  int *local_48;
  int local_44;
  int local_40;
  int local_3c [11];
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  undefined4 local_4;
  
  iVar7 = DAT_00a74b80;
  if ((DAT_00a828ac != 0) && (DAT_00a828ac != -1)) {
    piVar5 = (int *)&DAT_00a74b84;
    local_48 = (int *)&DAT_00a74b84;
    FUN_00550060(0);
    FUN_0056d380(local_3c + 1,0,0x38);
    local_8 = local_3c;
    local_3c[1] = 0x38;
    local_3c[2] = 0x12;
    local_10 = 0;
    local_c = 4;
    local_4 = 0;
    iVar2 = FUN_0050e880();
    if (iVar2 == 1) {
      if (0 < iVar7) {
        local_40 = iVar7;
        do {
          if (piVar5[0x2d] < 0) {
            if (piVar5[0x2e] != 0) {
              local_44 = 2;
              piVar3 = piVar5;
              do {
                piVar6 = piVar3 + 8;
                piVar8 = (int *)*piVar6;
                if (piVar8 != (int *)0x0) {
                  if (piVar3[1] == 0) {
                    iVar7 = 0;
                  }
                  else {
                    iVar7 = piVar3[2];
                  }
                  iVar2 = piVar3[7];
                  if ((iVar2 != iVar7) || (piVar3[6] != (uint)(0 < iVar7))) {
                    local_3c[0] = iVar7;
                    if (0 < iVar7 == 1) {
                      if (piVar3[6] == 1) {
                        if (iVar2 != iVar7) {
                          uVar10 = 0x20000100;
                          piVar9 = local_3c + 1;
                          pcVar4 = *(code **)(*piVar8 + 0x18);
                          goto LAB_0056b16a;
                        }
                      }
                      else if (piVar3[6] == 0) {
                        if (iVar2 != iVar7) {
                          (**(code **)(*piVar8 + 0x18))(piVar8,local_3c + 1,0x100);
                        }
                        piVar8 = (int *)*piVar6;
                        pcVar4 = *(code **)(*piVar8 + 0x1c);
                        uVar10 = 0;
                        piVar9 = (int *)0xffffffff;
LAB_0056b16a:
                        (*pcVar4)(piVar8,piVar9,uVar10);
                      }
                    }
                    else {
                      if (piVar3[6] != 0) {
                        (**(code **)(*piVar8 + 0x20))(piVar8);
                      }
                      if (piVar3[7] != iVar7) {
                        piVar8 = (int *)*piVar6;
                        pcVar4 = *(code **)(*piVar8 + 0x18);
                        uVar10 = 0x100;
                        piVar9 = local_3c + 1;
                        goto LAB_0056b16a;
                      }
                    }
                    piVar3[7] = iVar7;
                    piVar3[6] = piVar3[1];
                  }
                }
                local_44 = local_44 + -1;
                piVar3 = piVar6;
              } while (local_44 != 0);
            }
          }
          else {
            local_4c = 0;
            local_4a = 0;
            local_44 = 0;
            iVar7 = 0;
            while( true ) {
              if (piVar5[iVar7 * 8 + 1] == 0) {
                iVar2 = 0;
              }
              else {
                iVar2 = piVar5[iVar7 * 8 + 2];
              }
              if (iVar7 == 0) {
                local_4c = (undefined2)((iVar2 * 0xffff) / 10000);
              }
              else if (iVar7 == 1) {
                local_4a = (undefined2)((iVar2 * 0xffff) / 10000);
              }
              if (piVar5[iVar7 * 8 + 7] != iVar2) {
                local_44 = 1;
                piVar5[iVar7 * 8 + 7] = iVar2;
              }
              piVar5[iVar7 * 8 + 6] = piVar5[iVar7 * 8 + 1];
              if (1 < iVar7 + 1) break;
              iVar7 = iVar7 + 1;
              piVar5 = local_48;
            }
            if ((DAT_00a82898 != (code *)0x0) && (local_44 == 1)) {
              (*DAT_00a82898)(local_48[0x2d],&local_4c);
            }
            piVar5 = local_48;
          }
          piVar5 = piVar5 + 0x135;
          local_40 = local_40 + -1;
          local_48 = piVar5;
          if (local_40 == 0) {
            return 0;
          }
        } while( true );
      }
    }
    else if (0 < iVar7) {
      piVar5 = &DAT_00a74c38;
      local_40 = iVar7;
      do {
        if (*piVar5 < 0) {
          if (piVar5[1] != 0) {
            piVar3 = piVar5 + -0x25;
            iVar7 = 2;
            do {
              piVar8 = (int *)*piVar3;
              if ((piVar8 != (int *)0x0) && ((piVar3[-1] != 0 || (piVar3[-2] != 0)))) {
                local_3c[0] = 0;
                if (piVar3[-2] != 0) {
                  (**(code **)(*piVar8 + 0x20))(piVar8);
                }
                if (piVar3[-1] != 0) {
                  (**(code **)(*(int *)*piVar3 + 0x18))((int *)*piVar3,local_3c + 1,0x100);
                }
                piVar3[-1] = 0;
                piVar3[-2] = 0;
              }
              piVar3 = piVar3 + 8;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
        }
        else {
          bVar1 = false;
          local_4c = 0;
          local_4a = 0;
          piVar3 = piVar5 + -0x26;
          iVar7 = 2;
          do {
            if (*piVar3 != 0) {
              bVar1 = true;
              *piVar3 = 0;
            }
            piVar3[-1] = 0;
            piVar3 = piVar3 + 8;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          if ((DAT_00a82898 != (code *)0x0) && (bVar1)) {
            (*DAT_00a82898)(*piVar5,&local_4c);
          }
        }
        piVar5 = piVar5 + 0x135;
        local_40 = local_40 + -1;
      } while (local_40 != 0);
    }
  }
  return 0;
}

