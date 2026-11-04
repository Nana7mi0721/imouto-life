
uint FUN_00523780(int param_1,uint param_2)

{
  int *piVar1;
  uint in_EAX;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 local_8b4 [269];
  int local_480;
  undefined4 local_474;
  byte local_470;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_10;
  int *local_c;
  int *local_8;
  
  if ((((DAT_00cc47d0 != 0) && (-1 < (int)param_2)) &&
      (in_EAX = param_2 & 0x7c000000, in_EAX == DAT_00cc47f8)) &&
     (in_EAX = param_2 & 0xffff, (int)in_EAX < DAT_00cc4800)) {
    piVar1 = *(int **)(DAT_00cc47d4 + in_EAX * 4);
    local_8 = piVar1;
    if (((piVar1 != (int *)0x0) && (in_EAX = param_2 & 0x3ff0000, *piVar1 * 0x10000 == in_EAX)) &&
       (piVar1[4] == 0)) {
      if (*(char *)(piVar1[0x13] + 8) == '\0') {
        local_c = piVar1 + 0x22;
        if ((*(int *)(param_1 + 0x34) != 0) &&
           (iVar2 = FUN_005fbc30(*(undefined4 *)(param_1 + 0x38),1,0,0,0), iVar2 == 0)) {
          if (*(int *)(param_1 + 0x6c) != 0) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0x6c) = 1;
        }
        if (*(int *)(param_1 + 0xd8) != 2) {
          iVar2 = *(int *)(param_1 + 0x524);
          local_10 = piVar1[0x27];
          if ((*(char *)(*(int *)(piVar1[0x27] + 0x14) + 5) == *(char *)(iVar2 + 5)) &&
             (*(int *)(param_1 + 0xbc) != 1)) {
            local_24 = *(int *)(param_1 + 0xb8);
            iVar5 = FUN_005167e0();
            puVar10 = (undefined4 *)local_c[3];
            puVar8 = *(undefined4 **)(iVar2 + 0x434);
            iVar9 = (int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3;
            iVar7 = *(int *)(param_1 + 0xb4) * iVar9;
            iVar2 = *(int *)(iVar2 + 0x430) - iVar7;
            uVar3 = *(int *)(local_10 + 0xc) - iVar7;
            iVar6 = (int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2;
            iVar9 = (iVar7 + iVar6 * -4) / iVar9;
            if (iVar5 == 8) {
              do {
                iVar5 = iVar6;
                if (iVar6 != 0) {
                  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *puVar10 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar10 = puVar10 + 1;
                  }
                }
                iVar5 = iVar9;
                if (iVar9 != 0) {
                  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
                    puVar8 = (undefined4 *)((int)puVar8 + 1);
                    puVar10 = (undefined4 *)((int)puVar10 + 1);
                  }
                }
                puVar10 = (undefined4 *)((int)puVar10 + uVar3);
                puVar8 = (undefined4 *)((int)puVar8 + iVar2);
                local_24 = local_24 + -1;
              } while (local_24 != 0);
            }
            else if (iVar5 == 0x10) {
              do {
                iVar5 = iVar6;
                if (iVar6 != 0) {
                  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *puVar10 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar10 = puVar10 + 1;
                  }
                }
                iVar5 = iVar9;
                if (iVar9 != 0) {
                  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *(undefined2 *)puVar10 = *(undefined2 *)puVar8;
                    puVar8 = (undefined4 *)((int)puVar8 + 2);
                    puVar10 = (undefined4 *)((int)puVar10 + 2);
                  }
                }
                puVar10 = (undefined4 *)((int)puVar10 + uVar3);
                puVar8 = (undefined4 *)((int)puVar8 + iVar2);
                local_24 = local_24 + -1;
              } while (local_24 != 0);
            }
            else {
              do {
                for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
                  *puVar10 = *puVar8;
                  puVar8 = puVar8 + 1;
                  puVar10 = puVar10 + 1;
                }
                puVar10 = (undefined4 *)((int)puVar10 + uVar3);
                puVar8 = (undefined4 *)((int)puVar8 + iVar2);
                local_24 = local_24 + -1;
              } while (local_24 != 0);
            }
            return uVar3;
          }
        }
        if (*(int *)(param_1 + 0xbc) == 0) {
          uVar3 = FUN_00581490(*(undefined4 *)(param_1 + 0x524),0,piVar1 + 0x22,0,0,local_8[0x18],
                               local_8[0x19],0,0,0);
          return uVar3;
        }
        puVar10 = *(undefined4 **)(param_1 + 0x524);
        puVar8 = puVar10;
        puVar11 = &local_474;
        for (iVar2 = 0x10a; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar11 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar11 = puVar11 + 1;
        }
        local_40 = puVar10[0x10d];
        local_44 = puVar10[0x10c];
        iVar2 = puVar10[0x10a];
        local_4c = iVar2 / 2;
        local_48 = puVar10[0x10b];
        puVar10 = &local_474;
        puVar8 = local_8b4;
        for (iVar5 = 0x110; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar8 = puVar8 + 1;
        }
        local_480 = (uint)local_470 * (iVar2 / 2) + local_40;
        in_EAX = FUN_00581490(&local_474,local_8b4,local_c,0,0,local_8[0x18],local_8[0x19],0,0,0);
      }
      else {
        if (*(int *)(param_1 + 0x34) != 0) {
          iVar2 = FUN_005fc460(*(undefined4 *)(param_1 + 0x38));
          if (iVar2 == 0) {
            if ((DAT_00a37dc8 == 0) || (*(int *)(param_1 + 0xc4) != 0)) {
              uVar4 = *(undefined4 *)(param_1 + 0x38);
              uVar14 = 0;
              uVar13 = 0;
              uVar12 = 1;
            }
            else {
              uVar4 = *(undefined4 *)(param_1 + 0x38);
              uVar14 = 0;
              uVar13 = 1;
              uVar12 = 0;
            }
          }
          else {
            uVar4 = *(undefined4 *)(param_1 + 0x38);
            uVar14 = 1;
            uVar13 = 0;
            uVar12 = 0;
          }
          iVar2 = FUN_005fbc30(uVar4,uVar12,uVar13,uVar14,0);
          if ((iVar2 == 0) && (*(int *)(param_1 + 0x6c) != 0)) {
            return 0;
          }
          if (*(int *)(param_1 + 0x34) != 0) {
            if ((*(int *)(param_1 + 0xbc) == 0) &&
               (iVar2 = FUN_005fc460(*(undefined4 *)(param_1 + 0x38)), iVar2 != 0)) {
              uVar3 = FUN_005689c0(param_1,local_8);
              *(undefined4 *)(param_1 + 0x6c) = 1;
              return uVar3;
            }
            if (((*(int *)(param_1 + 0x34) != 0) && (*(int *)(param_1 + 0xc4) == 0)) &&
               (DAT_00a37dc8 != 0)) {
              if (*(int *)(param_1 + 0xbc) == 0) {
                uVar4 = FUN_005fc480(*(undefined4 *)(param_1 + 0x38));
                uVar4 = FUN_005fc470(*(undefined4 *)(param_1 + 0x38),param_2,0xd,uVar4);
                uVar3 = FUN_00594b60(uVar4);
                *(undefined4 *)(param_1 + 0x6c) = 1;
                return uVar3;
              }
              uVar4 = FUN_005fc480(*(undefined4 *)(param_1 + 0x38));
              uVar4 = FUN_005fc470(*(undefined4 *)(param_1 + 0x38),param_2,0,0,
                                   *(int *)(param_1 + 0xb4) / 2,*(undefined4 *)(param_1 + 0xb8),0,0,
                                   0xf,uVar4);
              uVar3 = FUN_00594bc0(uVar4);
              *(undefined4 *)(param_1 + 0x6c) = 1;
              return uVar3;
            }
          }
        }
        in_EAX = *(uint *)(param_1 + 0x528);
        if (-1 < (int)in_EAX) {
          uVar3 = FUN_00594b60(in_EAX,param_2,0xd,*(undefined4 *)(param_1 + 0x52c));
          return uVar3;
        }
        if (*(undefined4 **)(param_1 + 0x524) != (undefined4 *)0x0) {
          iVar2 = *(int *)(param_1 + 0xbc);
          puVar10 = *(undefined4 **)(param_1 + 0x524);
          puVar8 = &local_474;
          for (iVar5 = 0x110; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar8 = puVar8 + 1;
          }
          if (iVar2 != 0) {
            iVar5 = local_4c / 2;
            local_4c = iVar5;
            puVar10 = &local_474;
            puVar8 = local_8b4;
            for (iVar6 = 0x110; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar8 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar8 = puVar8 + 1;
            }
            local_480 = (uint)local_470 * iVar5 + local_40;
          }
          local_34 = local_8[0x14];
          local_30 = local_8[0x15];
          local_2c = local_8[0x18] + local_34;
          local_28 = local_8[0x19] + local_30;
          uVar3 = FUN_00518620(&local_34,0,0,param_2,&local_474,
                               -(uint)(iVar2 != 0) & (uint)local_8b4,0,0,0,0);
          return uVar3;
        }
      }
    }
  }
  return in_EAX;
}

