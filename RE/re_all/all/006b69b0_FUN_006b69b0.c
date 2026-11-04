
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 *
FUN_006b69b0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  undefined1 *puVar12;
  uint *local_134c;
  int *local_1348;
  undefined4 *local_1344;
  int local_1340;
  int local_133c;
  int local_1338;
  int local_1334;
  int local_1330;
  int local_132c;
  int local_1328;
  int local_1324;
  undefined4 *local_1320;
  undefined4 *local_131c;
  int local_1318;
  int local_1314;
  undefined4 *local_1310;
  int aiStack_130c [63];
  int local_1210;
  undefined4 *local_120c;
  int aiStack_1208 [63];
  int local_110c [65];
  int local_1008 [65];
  int local_f04 [65];
  undefined1 local_e00 [3580];
  undefined4 uStack_4;
  
  uStack_4 = 0x6b69ba;
  iVar4 = param_2[0x141];
  uVar6 = param_2[0x142];
  iVar1 = param_2[0x144];
  local_134c = (uint *)0x0;
  if (0 < iVar4) {
    piVar10 = &local_1210;
    for (iVar9 = iVar4; iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar10 = -200;
      piVar10 = piVar10 + 1;
    }
  }
  if (0 < iVar4) {
    piVar10 = &local_1314;
    for (iVar9 = iVar4; iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar10 = -200;
      piVar10 = piVar10 + 1;
    }
    if (0 < iVar4) {
      piVar10 = local_1008;
      for (iVar9 = iVar4; iVar9 != 0; iVar9 = iVar9 + -1) {
        *piVar10 = 0;
        piVar10 = piVar10 + 1;
      }
    }
    if (0 < iVar4) {
      piVar10 = local_110c;
      for (iVar9 = iVar4; iVar9 != 0; iVar9 = iVar9 + -1) {
        *piVar10 = 1;
        piVar10 = piVar10 + 1;
      }
      if (0 < iVar4) {
        piVar10 = local_f04;
        for (iVar9 = iVar4; iVar9 != 0; iVar9 = iVar9 + -1) {
          *piVar10 = -1;
          piVar10 = piVar10 + 1;
        }
      }
    }
  }
  local_1338 = iVar4;
  if (iVar4 == 0) {
    local_134c = (uint *)FUN_006b6f00(param_4,param_3,0,uVar6,local_e00,uVar6,iVar1);
  }
  else {
    local_133c = iVar4 + -1;
    if (local_133c < 1) {
      return (undefined4 *)0x0;
    }
    puVar12 = local_e00;
    puVar5 = param_2;
    do {
      iVar4 = FUN_006b6f00(param_4,param_3,*puVar5,puVar5[1],puVar12,uVar6,iVar1);
      local_134c = (uint *)((int)local_134c + iVar4);
      puVar12 = puVar12 + 0x38;
      puVar5 = puVar5 + 1;
      local_133c = local_133c + -1;
    } while (local_133c != 0);
    local_133c = 0;
    iVar4 = local_1338;
  }
  puVar5 = (undefined4 *)0x0;
  if (local_134c != (uint *)0x0) {
    local_1324 = -200;
    local_1320 = (undefined4 *)0xffffff38;
    FUN_006b70d0(local_e00,iVar4 + -1,&local_1324,&local_1320,iVar1);
    local_1210 = local_1324;
    local_1314 = local_1324;
    local_1310 = local_1320;
    local_120c = local_1320;
    local_1340 = 2;
    if (2 < iVar4) {
      local_134c = (uint *)0x0;
      local_1348 = param_2 + 0x84;
      do {
        local_133c = *local_1348;
        local_1318 = local_1008[local_133c];
        iVar4 = local_110c[local_133c];
        if (local_f04[local_1318] != iVar4) {
          local_1344 = *(undefined4 **)(iVar1 + 0x344 + iVar4 * 4);
          local_f04[local_1318] = iVar4;
          iVar9 = param_2[local_1318 + 0x82];
          iVar3 = param_2[iVar4 + 0x82];
          local_1334 = *(int *)(iVar1 + 0x344 + local_1318 * 4);
          local_132c = FUN_006b7580(&local_1210,&local_1314,local_1318);
          local_131c = (undefined4 *)FUN_006b7580(&local_1210,&local_1314,iVar4);
          if ((local_132c == -1) || (local_131c == (undefined4 *)0xffffffff)) {
                    /* WARNING: Subroutine does not return */
            _exit(1);
          }
          iVar2 = FUN_006b7350(local_1334,local_1344,local_132c,local_131c,param_4,param_3,iVar1);
          if (iVar2 != 0) {
            local_1330 = -200;
            local_1334 = -200;
            local_1328 = -200;
            local_1344 = (undefined4 *)0xffffff38;
            iVar9 = FUN_006b70d0(local_e00 + iVar9 * 0x38,local_133c - iVar9,&local_1330,&local_1334
                                 ,iVar1);
            iVar3 = FUN_006b70d0(local_e00 + local_133c * 0x38,iVar3 - local_133c,&local_1328,
                                 &local_1344,iVar1);
            if (iVar9 == 0) {
              iVar2 = local_1334;
            }
            else {
              local_1330 = local_132c;
              iVar2 = local_1328;
            }
            if (iVar3 == 0) {
              iVar11 = local_1328;
              puVar5 = local_1344;
            }
            else {
              iVar11 = iVar2;
              puVar5 = local_131c;
            }
            if ((iVar9 == 0) || (iVar3 == 0)) {
              (&local_1314)[local_1318] = local_1330;
              if (local_1318 == 0) {
                local_1210 = local_1330;
              }
              *(int *)((int)aiStack_1208 + (int)local_134c) = iVar2;
              *(int *)((int)aiStack_130c + (int)local_134c) = iVar11;
              (&local_1210)[iVar4] = (int)puVar5;
              if (iVar4 == 1) {
                local_1310 = puVar5;
              }
              if ((-1 < iVar2) || (-1 < iVar11)) {
                iVar9 = local_133c + -1;
                if (-1 < iVar9) {
                  piVar10 = local_110c + iVar9;
                  do {
                    if (*piVar10 != iVar4) break;
                    iVar9 = iVar9 + -1;
                    *piVar10 = local_1340;
                    piVar10 = piVar10 + -1;
                  } while (-1 < iVar9);
                }
                iVar4 = local_133c + 1;
                if (iVar4 < local_1338) {
                  piVar10 = local_1008 + iVar4;
                  do {
                    if (*piVar10 != local_1318) break;
                    iVar4 = iVar4 + 1;
                    *piVar10 = local_1340;
                    piVar10 = piVar10 + 1;
                  } while (iVar4 < local_1338);
                }
              }
              goto LAB_006b6d54;
            }
          }
          *(undefined4 *)((int)aiStack_1208 + (int)local_134c) = 0xffffff38;
          *(undefined4 *)((int)aiStack_130c + (int)local_134c) = 0xffffff38;
        }
LAB_006b6d54:
        local_1348 = local_1348 + 1;
        local_134c = (uint *)((int)local_134c + 4);
        local_1340 = local_1340 + 1;
      } while (local_1340 < local_1338);
      iVar4 = local_1338;
    }
    puVar5 = (undefined4 *)FUN_006ac620(param_1,iVar4 * 4);
    local_1344 = puVar5;
    uVar6 = FUN_006b7580(&local_1210,&local_1314,0);
    *puVar5 = uVar6;
    uVar6 = FUN_006b7580(&local_1210,&local_1314,1);
    puVar5[1] = uVar6;
    local_1340 = 2;
    if (2 < iVar4) {
      local_134c = puVar5 + 2;
      local_1348 = (int *)(iVar1 + 0x34c);
      piVar10 = param_2 + 0xc3;
      do {
        uVar7 = FUN_006b6eb0(*(undefined4 *)(iVar1 + 0x344 + piVar10[0x3f] * 4),
                             *(undefined4 *)(iVar1 + 0x344 + *piVar10 * 4),puVar5[piVar10[0x3f]],
                             puVar5[*piVar10],*local_1348);
        iVar4 = local_1340;
        uVar8 = FUN_006b7580(&local_1210,&local_1314,local_1340);
        if (((int)uVar8 < 0) || (uVar7 == uVar8)) {
          *local_134c = uVar7 | 0x8000;
        }
        else {
          *local_134c = uVar8;
        }
        local_1340 = iVar4 + 1;
        piVar10 = piVar10 + 1;
        local_1348 = local_1348 + 1;
        local_134c = local_134c + 1;
        puVar5 = local_1344;
      } while (local_1340 < local_1338);
    }
  }
  return puVar5;
}

