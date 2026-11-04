
undefined4 FUN_0054e0d0(undefined4 param_1,undefined1 *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined1 *puVar13;
  ushort *puVar14;
  int iVar15;
  undefined4 *local_4c;
  undefined1 *local_48;
  undefined1 *local_44;
  undefined4 local_40;
  uint local_38;
  undefined1 *local_34;
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  undefined1 local_10;
  undefined1 local_f;
  int local_e;
  int local_6;
  
  iVar8 = (int)param_2;
  local_4c = (undefined4 *)0x0;
  local_48 = (undefined1 *)0x0;
  local_40 = 0xffffffff;
  FUN_0056d380(&local_10,0,0xe);
  local_6 = 0x36;
  local_e = 0x36;
  local_10 = 0x42;
  local_f = 0x4d;
  switch(*(undefined1 *)((int)param_2 + 5)) {
  case 8:
    local_4c = (undefined4 *)
               FUN_0056e050(0x42c,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x19d);
    if (local_4c == (undefined4 *)0x0) {
      FUN_0056bb10(&DAT_007d5f74);
      goto LAB_0054e7c0;
    }
    iVar11 = *(int *)((int)param_2 + 0x428) + 3;
    iVar11 = ((int)(iVar11 + (iVar11 >> 0x1f & 3U)) >> 2) * 4;
    local_48 = (undefined1 *)
               FUN_0056e050(*(int *)((int)param_2 + 0x42c) * iVar11,
                            "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x1a7);
    if (local_48 == (undefined1 *)0x0) {
      FUN_0056bb10(&DAT_007d5f44);
      goto LAB_0054e7c0;
    }
    puVar9 = local_4c + 10;
    puVar13 = (undefined1 *)((int)puVar9 + (int)param_2 + (2 - (int)local_4c));
    iVar15 = (int)local_4c - (int)param_2;
    param_2 = (undefined1 *)0x100;
    do {
      *(undefined1 *)puVar9 = puVar13[-2];
      *(undefined1 *)((int)puVar9 + 1) = puVar13[-1];
      puVar13[iVar15] = *puVar13;
      *(undefined1 *)((int)puVar9 + 3) = 0;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 4;
      param_2 = (undefined1 *)((int)param_2 + -1);
    } while (param_2 != (undefined1 *)0x0);
    local_6 = local_6 + 0x400;
    local_e = local_e + 0x400 + *(int *)(iVar8 + 0x42c) * iVar11;
    *(undefined2 *)((int)local_4c + 0xe) = 8;
    *local_4c = 0x28;
    local_4c[1] = *(undefined4 *)(iVar8 + 0x428);
    local_4c[2] = *(undefined4 *)(iVar8 + 0x42c);
    *(undefined2 *)(local_4c + 3) = 1;
    local_4c[4] = 0;
    uVar12 = *(int *)(iVar8 + 0x42c) - 1;
    if (-1 < (int)uVar12) {
      param_2 = local_48;
      do {
        FUN_0056d420(param_2,*(int *)(iVar8 + 0x430) * uVar12 + *(int *)(iVar8 + 0x434),
                     *(undefined4 *)(iVar8 + 0x428));
        param_2 = param_2 + iVar11;
        uVar12 = uVar12 - 1;
      } while (uVar12 < 0x80000000);
    }
    thunk_FUN_00595680(param_1);
    iVar15 = thunk_FUN_00595690(param_1);
    if (iVar15 == 0) {
      FUN_0056bb10(&DAT_007d5f10);
      goto LAB_0054e7c0;
    }
    thunk_FUN_00595750(iVar15,&local_10,0xe,0);
    thunk_FUN_00595750(iVar15,local_4c,0x428,0);
    iVar11 = *(int *)(iVar8 + 0x42c) * iVar11;
    break;
  default:
    goto switchD_0054e12b_caseD_9;
  case 0x10:
  case 0x18:
  case 0x20:
    local_4c = (undefined4 *)
               FUN_0056e050(0x2c,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x1eb);
    if (local_4c == (undefined4 *)0x0) {
      FUN_0056bb10(&DAT_007d5f74);
      goto LAB_0054e7c0;
    }
    iVar8 = (*(int *)((int)param_2 + 0x428) + 1) * 3;
    iVar11 = ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) * 4;
    local_48 = (undefined1 *)
               FUN_0056e050(*(int *)((int)param_2 + 0x42c) * iVar11,
                            "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x1f5);
    if (local_48 == (undefined1 *)0x0) {
      FUN_0056bb10(&DAT_007d5f44);
      goto LAB_0054e7c0;
    }
    local_e = local_e + *(int *)((int)param_2 + 0x42c) * iVar11;
    *(undefined2 *)((int)local_4c + 0xe) = 0x18;
    *local_4c = 0x28;
    local_4c[1] = *(undefined4 *)((int)param_2 + 0x428);
    local_4c[2] = *(undefined4 *)((int)param_2 + 0x42c);
    *(undefined2 *)(local_4c + 3) = 1;
    local_4c[4] = 0;
    uVar12 = *(uint *)((int)param_2 + 0x18);
    if ((((uVar12 == 0xff0000) && (*(int *)((int)param_2 + 0x14) == 0xff00)) &&
        (*(int *)((int)param_2 + 0x10) == 0xff)) && (*(char *)((int)param_2 + 4) == '\x04')) {
      uVar12 = *(int *)((int)param_2 + 0x42c) - 1;
      if (-1 < (int)uVar12) {
        iVar8 = *(int *)((int)param_2 + 0x428);
        local_44 = local_48;
        do {
          puVar6 = (undefined1 *)
                   (*(int *)((int)param_2 + 0x430) * uVar12 + *(int *)((int)param_2 + 0x434));
          iVar15 = 0;
          puVar13 = local_44;
          if (0 < iVar8) {
            do {
              *puVar13 = puVar6[2];
              puVar13[1] = puVar6[1];
              puVar13[2] = *puVar6;
              iVar8 = *(int *)((int)param_2 + 0x428);
              iVar15 = iVar15 + 1;
              puVar6 = puVar6 + 4;
              puVar13 = puVar13 + 3;
            } while (iVar15 < iVar8);
          }
          local_44 = local_44 + iVar11;
          uVar12 = uVar12 - 1;
        } while (uVar12 < 0x80000000);
      }
    }
    else if (uVar12 == 0xff) {
      if (((*(int *)((int)param_2 + 0x14) == 0xff00) && (*(int *)((int)param_2 + 0x10) == 0xff0000))
         && (*(char *)((int)param_2 + 4) == '\x04')) {
        uVar12 = *(int *)((int)param_2 + 0x42c) - 1;
        if (-1 < (int)uVar12) {
          iVar8 = *(int *)((int)param_2 + 0x428);
          puVar13 = local_48;
          do {
            puVar7 = (undefined1 *)
                     (*(int *)((int)param_2 + 0x430) * uVar12 + *(int *)((int)param_2 + 0x434));
            iVar15 = 0;
            puVar6 = puVar13;
            if (0 < iVar8) {
              do {
                *puVar6 = *puVar7;
                puVar6[1] = puVar7[1];
                puVar6[2] = puVar7[2];
                iVar8 = *(int *)((int)param_2 + 0x428);
                iVar15 = iVar15 + 1;
                puVar7 = puVar7 + 4;
                puVar6 = puVar6 + 3;
              } while (iVar15 < iVar8);
            }
            puVar13 = puVar13 + iVar11;
            uVar12 = uVar12 - 1;
          } while (uVar12 < 0x80000000);
        }
      }
      else {
        if (((*(int *)((int)param_2 + 0x14) != 0xff00) ||
            (*(int *)((int)param_2 + 0x10) != 0xff0000)) || (*(char *)((int)param_2 + 4) != '\x03'))
        goto LAB_0054e598;
        uVar12 = *(int *)((int)param_2 + 0x42c) - 1;
        if (-1 < (int)uVar12) {
          iVar8 = *(int *)((int)param_2 + 0x428);
          puVar13 = local_48;
          do {
            puVar7 = (undefined1 *)
                     (*(int *)((int)param_2 + 0x430) * uVar12 + *(int *)((int)param_2 + 0x434));
            iVar15 = 0;
            puVar6 = puVar13;
            if (0 < iVar8) {
              do {
                *puVar6 = *puVar7;
                puVar6[1] = puVar7[1];
                puVar6[2] = puVar7[2];
                iVar8 = *(int *)((int)param_2 + 0x428);
                iVar15 = iVar15 + 1;
                puVar7 = puVar7 + 3;
                puVar6 = puVar6 + 3;
              } while (iVar15 < iVar8);
            }
            puVar13 = puVar13 + iVar11;
            uVar12 = uVar12 - 1;
          } while (uVar12 < 0x80000000);
        }
      }
    }
    else {
LAB_0054e598:
      local_34 = local_48;
      if (*(char *)((int)param_2 + 4) == '\x02') {
        local_1c = *(uint *)((int)param_2 + 0x10);
        bVar1 = *(byte *)((int)param_2 + 0xc);
        local_18 = (uint)bVar1;
        uVar5 = *(uint *)((int)param_2 + 0x14);
        bVar2 = *(byte *)((int)param_2 + 0xd);
        bVar3 = *(byte *)((int)param_2 + 0xe);
        local_14 = 8 - (uint)*(byte *)((int)param_2 + 8);
        cVar4 = *(char *)((int)param_2 + 10);
        local_20 = 0x10 - (uint)*(byte *)((int)param_2 + 9);
        local_38 = *(int *)((int)param_2 + 0x42c) - 1;
        if (-1 < (int)local_38) {
          iVar8 = *(int *)((int)param_2 + 0x428);
          do {
            puVar14 = (ushort *)
                      (*(int *)((int)param_2 + 0x430) * local_38 + *(int *)((int)param_2 + 0x434));
            local_44 = (undefined1 *)0x0;
            puVar13 = local_34;
            if (0 < iVar8) {
              do {
                uVar10 = (uint)*puVar14;
                puVar14 = puVar14 + 1;
                uVar10 = ((uVar10 & uVar12) >> (bVar3 & 0x1f)) << (0x18U - cVar4 & 0x1f) |
                         ((uVar10 & uVar5) >> (bVar2 & 0x1f)) << ((byte)local_20 & 0x1f) |
                         ((uVar10 & local_1c) >> (bVar1 & 0x1f)) << ((byte)local_14 & 0x1f);
                *puVar13 = (char)(uVar10 >> 0x10);
                puVar13[1] = (char)(uVar10 >> 8);
                puVar13[2] = (char)uVar10;
                iVar8 = *(int *)((int)param_2 + 0x428);
                local_44 = (undefined1 *)((int)local_44 + 1);
                puVar13 = puVar13 + 3;
              } while ((int)local_44 < iVar8);
            }
            local_34 = local_34 + iVar11;
            local_38 = local_38 - 1;
          } while (local_38 < 0x80000000);
        }
      }
      else {
        uVar12 = *(int *)((int)param_2 + 0x42c) - 1;
        if (-1 < (int)uVar12) {
          iVar8 = *(int *)((int)param_2 + 0x428);
          do {
            iVar15 = 0;
            puVar13 = local_34;
            if (0 < iVar8) {
              do {
                FUN_00549840(param_2,iVar15,uVar12,&local_1c,&local_18,&local_14,&local_20);
                *puVar13 = (undefined1)local_14;
                puVar13[1] = (undefined1)local_18;
                puVar13[2] = (undefined1)local_1c;
                iVar8 = *(int *)((int)param_2 + 0x428);
                iVar15 = iVar15 + 1;
                puVar13 = puVar13 + 3;
              } while (iVar15 < iVar8);
            }
            local_34 = local_34 + iVar11;
            uVar12 = uVar12 - 1;
          } while (uVar12 < 0x80000000);
        }
      }
    }
    thunk_FUN_00595680(param_1);
    iVar15 = thunk_FUN_00595690(param_1);
    if (iVar15 == 0) {
      FUN_0056bb10(&DAT_007d5f10);
      goto LAB_0054e7c0;
    }
    thunk_FUN_00595750(iVar15,&local_10,0xe,0);
    thunk_FUN_00595750(iVar15,local_4c,0x28,0);
    iVar11 = *(int *)((int)param_2 + 0x42c) * iVar11;
  }
  thunk_FUN_00595750(iVar15,local_48,iVar11,0);
  thunk_FUN_005956d0(iVar15);
switchD_0054e12b_caseD_9:
  local_40 = 0;
LAB_0054e7c0:
  if (local_4c != (undefined4 *)0x0) {
    FUN_0056e1d0(local_4c);
  }
  if (local_48 != (undefined1 *)0x0) {
    FUN_0056e1d0(local_48);
  }
  return local_40;
}

