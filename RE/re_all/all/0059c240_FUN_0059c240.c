
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 FUN_0059c240(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  int local_236c;
  int *local_2368;
  int *local_2364;
  int local_2360;
  int local_235c [4];
  int local_234c;
  int local_2348;
  int local_2344;
  undefined4 auStack_2340 [16];
  undefined4 auStack_2300 [64];
  byte local_2200 [256];
  byte abStack_2100 [256];
  byte abStack_2000 [256];
  byte abStack_1f00 [256];
  byte abStack_1e00 [256];
  byte abStack_1d00 [256];
  byte abStack_1c00 [512];
  byte abStack_1a00 [512];
  byte abStack_1800 [512];
  byte abStack_1600 [512];
  byte abStack_1400 [512];
  byte abStack_1200 [512];
  undefined4 auStack_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x59c24a;
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (*(uint *)(param_1 + 0x10) != param_2) {
    *(uint *)(param_1 + 0x10) = param_2;
    iVar4 = 0;
    do {
      *(uint *)(param_1 + iVar4 * 4) = (uint)((1 << ((byte)iVar4 & 0x1f) & param_2) != 0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    FUN_0056d380(local_2200,0xff,0x600);
    local_2368 = (int *)(param_1 + 0x14);
    iVar4 = 0;
    do {
      if (*(int *)(param_1 + iVar4 * 4) != 0) {
        pbVar7 = local_2200;
        iVar6 = 6;
        piVar9 = local_2368;
        do {
          FUN_0059c0c0(piVar9,pbVar7,iVar4);
          pbVar7 = pbVar7 + 0x100;
          piVar9 = (int *)((int)piVar9 + 0x5030);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar4 = iVar4 + 1;
      local_2368 = (int *)((int)local_2368 + 0x140c);
    } while (iVar4 < 4);
    local_2364 = (int *)(param_1 + 0x418);
    local_236c = param_1 + 0x2717c;
    local_2368 = local_235c;
    local_2360 = 0;
    local_2344 = local_236c;
    do {
      iVar4 = *local_2364;
      *local_2368 = 0;
      iVar6 = 0;
      while( true ) {
        for (; (iVar6 < iVar4 &&
               ((local_2200[iVar6 + local_2360] == 0xff ||
                (*(byte *)(local_236c + iVar6) == local_2200[iVar6 + local_2360]))));
            iVar6 = iVar6 + 1) {
        }
        if (iVar6 == iVar4) break;
        iVar2 = *local_2368;
        iVar3 = (iVar2 + local_2360) * 2;
        abStack_1c00[iVar3] = (byte)iVar6;
        for (; ((iVar6 < iVar4 && (local_2200[iVar6 + local_2360] != 0xff)) &&
               (*(byte *)(iVar6 + local_236c) != local_2200[iVar6 + local_2360])); iVar6 = iVar6 + 1
            ) {
        }
        abStack_1c00[iVar3 + 1] = (byte)iVar6;
        *local_2368 = iVar2 + 1;
      }
      local_2364 = local_2364 + 0x140c;
      local_236c = local_236c + 0x100;
      local_2360 = local_2360 + 0x100;
      local_2368 = local_2368 + 1;
    } while (local_2360 < 0x600);
    FUN_0056d420(local_2344,local_2200,0x600);
    iVar4 = 0;
    if (0 < local_235c[0]) {
      do {
        uVar10 = (uint)abStack_1c00[iVar4 * 2];
        uVar8 = (uint)abStack_1c00[iVar4 * 2 + 1];
        if (uVar10 < uVar8) {
          iVar6 = uVar10 << 4;
          uVar5 = uVar10;
          do {
            puVar1 = (undefined4 *)((uint)local_2200[uVar5] * 0x140c + iVar6 + param_1 + 0x420);
            *(undefined4 *)((int)auStack_1000 + iVar6) = *puVar1;
            *(undefined4 *)((int)auStack_1000 + iVar6 + 4) = puVar1[1];
            *(undefined4 *)((int)auStack_1000 + iVar6 + 8) = puVar1[2];
            *(undefined4 *)((int)auStack_1000 + iVar6 + 0xc) = puVar1[3];
            uVar5 = uVar5 + 1;
            iVar6 = iVar6 + 0x10;
          } while ((int)uVar5 < (int)uVar8);
        }
        FUN_005d3c50(uVar10,auStack_1000 + uVar10 * 4,uVar8 - uVar10);
        FUN_0056d420((uVar10 + 0x1fd4) * 0x10 + param_1,auStack_1000 + uVar10 * 4,
                     (uVar8 - uVar10) * 0x10);
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_235c[0]);
    }
    local_236c = 0;
    if (0 < local_235c[1]) {
      do {
        uVar8 = (uint)abStack_1a00[local_236c * 2];
        uVar10 = (uint)abStack_1a00[local_236c * 2 + 1];
        if (uVar8 < uVar10) {
          iVar4 = uVar8 << 4;
          uVar5 = uVar8;
          do {
            puVar1 = (undefined4 *)((uint)abStack_2100[uVar5] * 0x140c + iVar4 + 0x5450 + param_1);
            *(undefined4 *)((int)auStack_2300 + iVar4) = *puVar1;
            *(undefined4 *)((int)auStack_2300 + iVar4 + 4) = puVar1[1];
            *(undefined4 *)((int)auStack_2300 + iVar4 + 8) = puVar1[2];
            *(undefined4 *)((int)auStack_2300 + iVar4 + 0xc) = puVar1[3];
            uVar5 = uVar5 + 1;
            iVar4 = iVar4 + 0x10;
          } while ((int)uVar5 < (int)uVar10);
        }
        FUN_005d3c70(uVar8,auStack_2300 + uVar8 * 4,uVar10 - uVar8);
        FUN_0056d420(uVar8 * 0x10 + 0x2114c + param_1,auStack_2300 + uVar8 * 4,
                     (uVar10 - uVar8) * 0x10);
        local_236c = local_236c + 1;
      } while (local_236c < local_235c[1]);
    }
    iVar4 = 0;
    if (0 < local_235c[2]) {
      do {
        uVar10 = (uint)abStack_1800[iVar4 * 2];
        uVar5 = (uint)abStack_1800[iVar4 * 2 + 1];
        uVar8 = uVar10;
        if (uVar10 < uVar5) {
          do {
            auStack_2340[uVar8] =
                 *(undefined4 *)(param_1 + 0xa480 + ((uint)abStack_2000[uVar8] * 0x503 + uVar8) * 4)
            ;
            uVar8 = uVar8 + 1;
          } while ((int)uVar8 < (int)uVar5);
        }
        FUN_005d3c90(uVar10,auStack_2340 + uVar10,uVar5 - uVar10);
        FUN_0056d420(param_1 + 0x22558 + uVar10 * 4,auStack_2340 + uVar10,(uVar5 - uVar10) * 4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_235c[2]);
    }
    local_236c = 0;
    if (0 < local_235c[3]) {
      do {
        uVar8 = (uint)abStack_1600[local_236c * 2];
        uVar10 = (uint)abStack_1600[local_236c * 2 + 1];
        if (uVar8 < uVar10) {
          iVar4 = uVar8 << 4;
          uVar5 = uVar8;
          do {
            puVar1 = (undefined4 *)((uint)abStack_1f00[uVar5] * 0x140c + iVar4 + 0xf4b0 + param_1);
            *(undefined4 *)((int)auStack_1000 + iVar4) = *puVar1;
            *(undefined4 *)((int)auStack_1000 + iVar4 + 4) = puVar1[1];
            *(undefined4 *)((int)auStack_1000 + iVar4 + 8) = puVar1[2];
            *(undefined4 *)((int)auStack_1000 + iVar4 + 0xc) = puVar1[3];
            uVar5 = uVar5 + 1;
            iVar4 = iVar4 + 0x10;
          } while ((int)uVar5 < (int)uVar10);
        }
        FUN_005d3d40(uVar8,auStack_1000 + uVar8 * 4,uVar10 - uVar8);
        FUN_0056d420(uVar8 * 0x10 + 0x23964 + param_1,auStack_1000 + uVar8 * 4,
                     (uVar10 - uVar8) * 0x10);
        local_236c = local_236c + 1;
      } while (local_236c < local_235c[3]);
    }
    iVar4 = 0;
    if (0 < local_234c) {
      do {
        uVar10 = (uint)abStack_1400[iVar4 * 2];
        uVar8 = (uint)abStack_1400[iVar4 * 2 + 1];
        if (uVar10 < uVar8) {
          iVar6 = uVar10 << 4;
          uVar5 = uVar10;
          do {
            puVar1 = (undefined4 *)((uint)abStack_1e00[uVar5] * 0x140c + iVar6 + 0x144e0 + param_1);
            *(undefined4 *)((int)auStack_2300 + iVar6) = *puVar1;
            *(undefined4 *)((int)auStack_2300 + iVar6 + 4) = puVar1[1];
            *(undefined4 *)((int)auStack_2300 + iVar6 + 8) = puVar1[2];
            *(undefined4 *)((int)auStack_2300 + iVar6 + 0xc) = puVar1[3];
            uVar5 = uVar5 + 1;
            iVar6 = iVar6 + 0x10;
          } while ((int)uVar5 < (int)uVar8);
        }
        FUN_005d3d60(uVar10,auStack_2300 + uVar10 * 4,uVar8 - uVar10);
        FUN_0056d420((uVar10 + 0x24d7) * 0x10 + param_1,auStack_2300 + uVar10 * 4,
                     (uVar8 - uVar10) * 0x10);
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_234c);
    }
    iVar4 = 0;
    if (0 < local_2348) {
      do {
        uVar10 = (uint)abStack_1200[iVar4 * 2];
        uVar5 = (uint)abStack_1200[iVar4 * 2 + 1];
        uVar8 = uVar10;
        if (uVar10 < uVar5) {
          do {
            auStack_2340[uVar8] =
                 *(undefined4 *)
                  (param_1 + 0x19510 + ((uint)abStack_1d00[uVar8] * 0x503 + uVar8) * 4);
            uVar8 = uVar8 + 1;
          } while ((int)uVar8 < (int)uVar5);
        }
        FUN_005d3d80(uVar10,auStack_2340 + uVar10,uVar5 - uVar10);
        FUN_0056d420(param_1 + 0x2617c + uVar10 * 4,auStack_2340 + uVar10,(uVar5 - uVar10) * 4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_2348);
    }
  }
  return 0;
}

