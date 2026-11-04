
int * FUN_006b0640(int param_1)

{
  size_t _Size;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar1 = param_1;
  piVar2 = _calloc(1,0x28);
  piVar2[9] = 1;
  iVar3 = FUN_00797830(param_1,0x18);
  if (iVar3 == 0x564342) {
    iVar3 = FUN_00797830(param_1,0x10);
    *piVar2 = iVar3;
    iVar3 = FUN_00797830(param_1,0x18);
    piVar2[1] = iVar3;
    if (iVar3 != -1) {
      iVar4 = FUN_006afc40(*piVar2);
      iVar3 = FUN_006afc40(iVar3);
      if (iVar4 + iVar3 < 0x19) {
        iVar3 = FUN_00797830(param_1,1);
        if (iVar3 == 0) {
          iVar3 = FUN_00797830(param_1,1);
          _Size = piVar2[1];
          iVar4 = FUN_00797940(param_1);
          if (*(int *)(param_1 + 0x10) - iVar4 <
              (int)(((-(uint)(iVar3 != 0) & 0xfffffffc) + 5) * _Size + 7) >> 3) goto LAB_006b091a;
          pvVar5 = _malloc(_Size);
          piVar2[2] = (int)pvVar5;
          if (iVar3 == 0) {
            iVar3 = 0;
            if (0 < piVar2[1]) {
              do {
                iVar4 = FUN_00797830(param_1,5);
                if (iVar4 == -1) goto LAB_006b091a;
                *(char *)(piVar2[2] + iVar3) = (char)iVar4 + '\x01';
                iVar3 = iVar3 + 1;
              } while (iVar3 < piVar2[1]);
            }
          }
          else {
            iVar3 = 0;
            if (0 < piVar2[1]) {
              do {
                iVar4 = FUN_00797830(param_1,1);
                if (iVar4 == 0) {
                  *(undefined1 *)(piVar2[2] + iVar3) = 0;
                }
                else {
                  iVar4 = FUN_00797830(param_1,5);
                  if (iVar4 == -1) goto LAB_006b091a;
                  *(char *)(piVar2[2] + iVar3) = (char)iVar4 + '\x01';
                }
                iVar3 = iVar3 + 1;
              } while (iVar3 < piVar2[1]);
            }
          }
        }
        else {
          if (iVar3 != 1) goto LAB_006b091a;
          param_1 = FUN_00797830(param_1,5);
          iVar3 = param_1 + 1;
          if (iVar3 == 0) goto LAB_006b091a;
          pvVar5 = _malloc(piVar2[1]);
          piVar2[2] = (int)pvVar5;
          iVar4 = piVar2[1];
          iVar7 = 0;
          if (0 < iVar4) {
            do {
              uVar6 = FUN_006afc40(iVar4 - iVar7);
              iVar4 = FUN_00797830(iVar1,uVar6);
              if (((((iVar4 == -1) || (0x1f < param_1)) || (piVar2[1] - iVar7 < iVar4)) ||
                  ((0 < iVar4 && (1 < iVar4 + -1 >> ((byte)param_1 & 0x1f))))) || (0x1f < param_1))
              goto LAB_006b091a;
              if (0 < iVar4) {
                do {
                  iVar7 = iVar7 + 1;
                  iVar4 = iVar4 + -1;
                  *(char *)(piVar2[2] + -1 + iVar7) = (char)iVar3;
                } while (iVar4 != 0);
              }
              iVar4 = piVar2[1];
              iVar3 = iVar3 + 1;
              param_1 = param_1 + 1;
            } while (iVar7 < iVar4);
          }
        }
        iVar3 = FUN_00797830(iVar1,4);
        piVar2[3] = iVar3;
        if (iVar3 == 0) {
          return piVar2;
        }
        if ((0 < iVar3) && (iVar3 < 3)) {
          iVar3 = FUN_00797830(iVar1,0x20);
          piVar2[4] = iVar3;
          iVar3 = FUN_00797830(iVar1,0x20);
          piVar2[5] = iVar3;
          iVar3 = FUN_00797830(iVar1,4);
          piVar2[6] = iVar3 + 1;
          iVar3 = FUN_00797830(iVar1,1);
          piVar2[7] = iVar3;
          if (iVar3 != -1) {
            iVar3 = 0;
            if (piVar2[3] == 1) {
              if (*piVar2 == 0) {
                iVar3 = 0;
              }
              else {
                iVar3 = FUN_006afe60(piVar2);
              }
            }
            else if (piVar2[3] == 2) {
              iVar3 = *piVar2 * piVar2[1];
            }
            iVar4 = FUN_00797940(iVar1);
            if (iVar3 * piVar2[6] + 7 >> 3 <= *(int *)(iVar1 + 0x10) - iVar4) {
              pvVar5 = _malloc(iVar3 * 4);
              iVar4 = 0;
              piVar2[8] = (int)pvVar5;
              if (0 < iVar3) {
                do {
                  uVar6 = FUN_00797830(iVar1,piVar2[6]);
                  *(undefined4 *)(piVar2[8] + iVar4 * 4) = uVar6;
                  iVar4 = iVar4 + 1;
                } while (iVar4 < iVar3);
              }
              if (iVar3 == 0) {
                return piVar2;
              }
              if (*(int *)(piVar2[8] + -4 + iVar3 * 4) != -1) {
                return piVar2;
              }
            }
          }
        }
      }
    }
  }
LAB_006b091a:
  FUN_006b00c0(piVar2);
  return (int *)0x0;
}

