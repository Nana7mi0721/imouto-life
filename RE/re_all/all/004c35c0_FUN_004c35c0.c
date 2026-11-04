
void __fastcall FUN_004c35c0(int param_1)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int local_34;
  int local_30;
  int local_28;
  int local_24;
  int local_1c;
  int local_14;
  int local_c;
  
  *(int *)(param_1 + 0x170) = (*(int *)(param_1 + 0x170) + 3) % 0x8c;
  iVar4 = FUN_004febf1(*(int *)(param_1 + 0x170) + -0x46);
  *(int *)(param_1 + 0x174) = iVar4 + 0xb9;
  *(int *)(param_1 + 0x164) = (*(int *)(param_1 + 0x164) + 1) % (*(int *)(param_1 + 0x160) * 5);
  *(int *)(param_1 + 0x198) = *(int *)(param_1 + 0x198) + -1;
  if (DAT_00a14090 == DAT_00a140b8) {
    if (*(int *)(param_1 + 0x194) < 1) {
      FUN_004c2d50();
      if ((*(int *)(param_1 + 0x17c) == 0) || (*(int *)(param_1 + 0x128) == 0)) {
        if (*(int *)(param_1 + 0x198) < 1) {
          if (*(int *)(param_1 + 0x16c) + -0x3c < 0) {
            local_34 = 0;
          }
          else {
            local_34 = *(int *)(param_1 + 0x16c) + -0x3c;
          }
          *(int *)(param_1 + 0x16c) = local_34;
        }
      }
      else {
        if (*(int *)(param_1 + 0x16c) + 0x40 < 0x100) {
          local_30 = *(int *)(param_1 + 0x16c) + 0x40;
        }
        else {
          local_30 = 0xff;
        }
        *(int *)(param_1 + 0x16c) = local_30;
      }
      if (*(char *)(param_1 + 300) == '\0') {
        cVar3 = operator!=<>(&DAT_00a14014,&DAT_007d0621);
        if (cVar3 == '\0') {
          if (*(int *)(param_1 + 0x17c) == 0) {
            DAT_00a140c0 = 0xffffffff;
          }
          else {
            *(undefined4 *)(param_1 + 0x17c) = 0;
            DAT_00a1405c = 0;
            DAT_00a140c0 = 0xffffffff;
          }
        }
        else {
          *(undefined1 *)(param_1 + 300) = 1;
          DAT_00a1405c = 1;
          *(undefined4 *)(param_1 + 0x17c) = 1;
          *(undefined4 *)(param_1 + 0x194) = 4;
          FUN_004c3d20();
          FUN_004c3fa0();
        }
      }
      else {
        cVar3 = FUN_004c2d10();
        if (cVar3 != '\0') {
          if (DAT_00a140c5 == '\0') {
            if (DAT_00a14634 == 8) {
              *(int *)(param_1 + 0x178) =
                   (*(int *)(param_1 + 0x178) + -1 + DAT_00a14038) % DAT_00a14038;
              local_c = *(int *)(param_1 + 0x178);
              bVar2 = false;
              for (local_14 = 0; local_14 < DAT_00a14038; local_14 = local_14 + 1) {
                piVar5 = (int *)FUN_004ce990(local_c);
                if (*piVar5 != 0) {
                  bVar2 = true;
                  break;
                }
                local_c = (local_c + -1 + DAT_00a14038) % DAT_00a14038;
              }
              if (bVar2) {
                *(int *)(param_1 + 0x178) = local_c;
              }
              FUN_004c3c50(2,DAT_00a18a5c,0,0);
            }
            if (DAT_00a14634 == 2) {
              *(int *)(param_1 + 0x178) = (*(int *)(param_1 + 0x178) + 1) % DAT_00a14038;
              local_1c = *(int *)(param_1 + 0x178);
              bVar2 = false;
              for (local_24 = 0; local_24 < DAT_00a14038; local_24 = local_24 + 1) {
                piVar5 = (int *)FUN_004ce990(local_1c);
                if (*piVar5 != 0) {
                  bVar2 = true;
                  break;
                }
                local_1c = (local_1c + 1) % DAT_00a14038;
              }
              if (bVar2) {
                *(int *)(param_1 + 0x178) = local_1c;
              }
              FUN_004c3c50(2,DAT_00a18a5c,0,0);
            }
            if (DAT_00a14670 != '\0') {
              FUN_004c1ae0();
              FUN_004c3c50(2,DAT_00a18a58,0,0);
            }
            if ((DAT_00a1403c != -1) && (DAT_00a14671 != '\0')) {
              *(int *)(param_1 + 0x178) = DAT_00a1403c;
              FUN_004c1ae0();
              FUN_004c3c50(2,DAT_00a18a60,0,0);
            }
            if (((DAT_00a14040 & 1) != 0) && (DAT_00a14610 != '\0')) {
              *(undefined4 *)(param_1 + 0x178) = 0x62;
              FUN_004c1ae0();
              FUN_004c3c50(2,DAT_00a18a60,0,0);
            }
            if (((DAT_00a14040 & 2) != 0) && (DAT_00a14611 != '\0')) {
              *(undefined4 *)(param_1 + 0x178) = 99;
              FUN_004c1ae0();
              FUN_004c3c50(2,DAT_00a18a60,0,0);
            }
            if (DAT_00a18af0 == 1) {
              for (local_28 = 0; local_28 < DAT_00a14038; local_28 = local_28 + 1) {
                if (((*(int *)(param_1 + 0x180) + -3 + (DAT_0084b264 << 2) / 10 < DAT_00a14620) &&
                    (piVar5 = (int *)FUN_004ce990(local_28),
                    *(int *)(param_1 + 0x184) + *piVar5 + 1 + (DAT_0084b264 << 2) / 10 <
                    DAT_00a14624)) &&
                   (DAT_00a14620 <
                    (int)(((*(int *)(param_1 + 0x180) + *(int *)(param_1 + 0x188)) -
                          (DAT_0084b264 << 2) / 10) +
                         ((-(uint)(*DAT_00a16674 != '\x10') & 0x17) - 9)))) {
                  piVar5 = (int *)FUN_004ce990(local_28);
                  iVar4 = *(int *)(param_1 + 0x184);
                  iVar1 = *piVar5;
                  piVar5 = (int *)FUN_004ce990(local_28);
                  if (DAT_00a14624 < iVar4 + iVar1 + *piVar5 + 1 + (DAT_0084b264 << 2) / 10) {
                    *(int *)(param_1 + 0x178) = local_28;
                    break;
                  }
                }
              }
              if (DAT_00a1461d != '\0') {
                FUN_004c1ae0();
                FUN_004c3c50(2,DAT_00a18a58,0,0);
              }
              if ((DAT_00a1403c != -1) && (DAT_00a1461e != '\0')) {
                *(int *)(param_1 + 0x178) = DAT_00a1403c;
                FUN_004c1ae0();
                FUN_004c3c50(2,DAT_00a18a60,0,0);
              }
            }
            DAT_00a140c0 = *(undefined4 *)(param_1 + 0x178);
          }
          else {
            if ((DAT_00a14040 & 4) != 0) {
              *(undefined4 *)(param_1 + 0x178) = 100;
            }
            FUN_004c1ae0();
          }
        }
      }
    }
    else {
      *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + -1;
      if (*(int *)(param_1 + 0x16c) == 0xff) {
        *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + -2;
      }
    }
  }
  else {
    DAT_00a140c0 = 0xffffffff;
  }
  return;
}

