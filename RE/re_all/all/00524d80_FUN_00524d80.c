
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_00524d80(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int local_11bc;
  undefined4 local_11b8;
  undefined4 local_11b4;
  undefined4 local_11b0;
  undefined4 local_11ac;
  int local_11a8;
  int local_11a4;
  undefined1 local_11a0 [148];
  undefined4 local_110c;
  undefined1 local_1100 [1064];
  undefined4 local_cd8;
  undefined4 local_cd4;
  undefined1 local_cc0 [1064];
  undefined4 local_898;
  undefined4 local_894;
  undefined1 local_880 [1088];
  undefined1 local_440 [1084];
  undefined4 uStack_4;
  
  uStack_4 = 0x524d8a;
  FUN_0056bb10(&DAT_007d569c);
  iVar8 = DAT_00cc480c;
  iVar9 = 0;
  local_11a4 = DAT_00cc480c;
  bVar4 = false;
  bVar5 = false;
  local_11bc = 0;
  bVar6 = false;
  bVar7 = false;
  iVar2 = DAT_00cc4808;
  iVar1 = DAT_00cc4808;
  if (DAT_00cc47d0 != 0) {
    for (; local_11a8 = iVar1, DAT_00cc4808 = local_11a8, iVar2 <= iVar8; iVar2 = iVar2 + 1) {
      iVar1 = *(int *)(DAT_00cc47d4 + iVar2 * 4);
      if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x4c), iVar1 != 0)) {
        *(undefined4 *)(iVar1 + 0x30) = 0;
      }
      iVar1 = DAT_00cc4808;
    }
    if (local_11a8 <= iVar8) {
      do {
        iVar2 = *(int *)(DAT_00cc47d4 + local_11a8 * 4);
        if (((iVar2 != 0) && (iVar8 = *(int *)(iVar2 + 0x38), iVar8 != 0)) &&
           (*(int *)(*(int *)(iVar2 + 0x4c) + 0x30) == 0)) {
          iVar1 = *(int *)(*(int *)(iVar2 + 0x4c) + 4);
          if (((iVar1 == 0xc) || (iVar1 == 0xd)) ||
             ((iVar1 == 0xe || ((iVar1 == 0xf || (iVar1 == 0x10)))))) {
            bVar3 = true;
          }
          else {
            bVar3 = false;
          }
          if (*(int *)(iVar8 + 4) == 0) {
            if (*(int *)(iVar8 + 0x10) == 0) {
              if (*(int *)(iVar8 + 8) != 0) {
                if (bVar3) {
                  iVar1 = *(int *)(iVar8 + 8);
                  local_11b0 = *(undefined4 *)(iVar1 + 0x428);
                  local_11ac = *(undefined4 *)(iVar1 + 0x42c);
                  local_11b8 = 0;
                  local_11b4 = 0;
                  FUN_00518620(&local_11b8,0,0,*(undefined4 *)(iVar2 + 4),iVar1,
                               *(undefined4 *)(iVar8 + 0xc),0,0,1);
                  *(undefined4 *)(*(int *)(iVar2 + 0x4c) + 0x30) = 1;
                }
                else {
                  FUN_00523c60(*(undefined4 *)(iVar8 + 8),*(undefined4 *)(iVar8 + 0xc),
                               *(undefined4 *)(iVar2 + 0x3c),*(undefined4 *)(iVar2 + 0x40),
                               *(undefined4 *)(iVar2 + 4),DAT_00a37f54 == 0,0);
                }
              }
            }
            else {
              if (((((local_11bc == 0) || (!bVar6)) ||
                   (iVar1 = *(int *)(local_11bc + 0x38),
                   *(int *)(iVar8 + 0x10) != *(int *)(iVar1 + 0x10))) ||
                  ((*(int *)(iVar8 + 0x18) != *(int *)(iVar1 + 0x18) ||
                   (*(int *)(iVar8 + 0x20) != *(int *)(iVar1 + 0x20))))) ||
                 (*(int *)(iVar8 + 0x24) != *(int *)(iVar1 + 0x24))) {
                if (bVar6) {
                  FUN_005421c0(local_1100);
                  bVar6 = false;
                }
                if (bVar7) {
                  FUN_005421c0(local_440);
                  bVar7 = false;
                }
                FUN_00540930(local_11a0,0);
                local_110c = *(undefined4 *)(*(int *)(iVar2 + 0x38) + 0x24);
                iVar8 = *(int *)(iVar2 + 0x38);
                iVar8 = FUN_0054f230(local_11a0,0,*(undefined4 *)(iVar8 + 0x10),
                                     *(undefined4 *)(iVar8 + 0x14),1,*(undefined4 *)(iVar8 + 0x18),
                                     *(undefined4 *)(iVar8 + 0x1c),1,local_1100,local_440,
                                     *(undefined4 *)(iVar8 + 0x20));
                if (iVar8 == -1) {
                  FUN_0056bca0(&DAT_007d5634);
                  local_11bc = iVar2;
                  goto LAB_00525213;
                }
                bVar6 = true;
                if (iVar8 == 0) {
                  bVar7 = true;
                }
              }
              if (bVar3) {
                local_11b0 = local_cd8;
                local_11ac = local_cd4;
                local_11b8 = 0;
                local_11b4 = 0;
                FUN_00518620(&local_11b8,0,0,*(undefined4 *)(iVar2 + 4),local_1100,
                             ~-(uint)!bVar7 & (uint)local_440,0,0,1);
                *(undefined4 *)(*(int *)(iVar2 + 0x4c) + 0x30) = 1;
                local_11bc = iVar2;
              }
              else {
                FUN_00523c60(local_1100,~-(uint)!bVar7 & (uint)local_440,
                             *(undefined4 *)(iVar2 + 0x3c),*(undefined4 *)(iVar2 + 0x40),
                             *(undefined4 *)(iVar2 + 4),DAT_00a37f54 == 0,0);
                local_11bc = iVar2;
              }
            }
          }
          else {
            if (((iVar9 == 0) || (!bVar4)) ||
               ((iVar1 = *(int *)(*(int *)(iVar9 + 0x38) + 4), iVar1 == 0 ||
                (iVar8 = FUN_0056d130(*(int *)(iVar8 + 4),iVar1), iVar8 != 0)))) {
LAB_00524e95:
              if (bVar4) {
                FUN_005421c0(local_cc0);
                bVar4 = false;
              }
              if (bVar5) {
                FUN_005421c0(local_880);
                bVar5 = false;
              }
              FUN_00540930(local_11a0,0);
              local_110c = *(undefined4 *)(*(int *)(iVar2 + 0x38) + 0x24);
              iVar8 = FUN_0054f230(local_11a0,*(undefined4 *)(*(int *)(iVar2 + 0x38) + 4),0,0,0,0,0,
                                   0,local_cc0,local_880,
                                   *(undefined4 *)(*(int *)(iVar2 + 0x38) + 0x20));
              if (iVar8 == -1) {
                FUN_0056bc50(L"Image File Load Error : %s",
                             *(undefined4 *)(*(int *)(iVar2 + 0x38) + 4));
                iVar9 = iVar2;
                goto LAB_00525213;
              }
              bVar4 = true;
              if (iVar8 == 0) {
                bVar5 = true;
              }
            }
            else if ((*(int *)(*(int *)(iVar2 + 0x38) + 0x20) !=
                      *(int *)(*(int *)(iVar9 + 0x38) + 0x20)) ||
                    (*(int *)(*(int *)(iVar2 + 0x38) + 0x24) !=
                     *(int *)(*(int *)(iVar9 + 0x38) + 0x24))) goto LAB_00524e95;
            if (bVar3) {
              local_11b0 = local_898;
              local_11ac = local_894;
              local_11b8 = 0;
              local_11b4 = 0;
              FUN_00518620(&local_11b8,0,0,*(undefined4 *)(iVar2 + 4),local_cc0,
                           ~-(uint)!bVar5 & (uint)local_880,0,0,1);
              *(undefined4 *)(*(int *)(iVar2 + 0x4c) + 0x30) = 1;
              iVar9 = iVar2;
            }
            else {
              FUN_00523c60(local_cc0,~-(uint)!bVar5 & (uint)local_880,*(undefined4 *)(iVar2 + 0x3c),
                           *(undefined4 *)(iVar2 + 0x40),*(undefined4 *)(iVar2 + 4),
                           DAT_00a37f54 == 0,0);
              iVar9 = iVar2;
            }
          }
        }
LAB_00525213:
        local_11a8 = local_11a8 + 1;
      } while (local_11a8 <= local_11a4);
      if (bVar4) {
        FUN_005421c0(local_cc0);
      }
      if (bVar5) {
        FUN_005421c0(local_880);
      }
      if (bVar6) {
        FUN_005421c0(local_1100);
      }
      if (bVar7) {
        FUN_005421c0(local_440);
      }
    }
  }
  FUN_0056bb10(&DAT_007d5610);
  return;
}

