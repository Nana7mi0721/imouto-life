
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0079d040(int param_1,undefined2 *param_2,int param_3,int param_4)

{
  short *psVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int aiStack_3c [5];
  undefined4 *local_1c;
  int local_18 [2];
  undefined4 *local_10;
  int local_c;
  uint local_8;
  
  aiStack_3c[4] = 0x79d063;
  iVar3 = -(*(int *)(param_1 + 0x10c) * 4 + 0x10);
  puVar8 = (undefined4 *)((int)aiStack_3c + iVar3 + 0x14);
  local_1c = (undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)aiStack_3c + iVar3 + 0x14) = *local_1c;
  local_10 = (undefined4 *)((int)aiStack_3c + iVar3 + 0x14);
  *(undefined4 *)((int)aiStack_3c + iVar3 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)((int)local_18 + iVar3 + -8) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)local_18 + iVar3 + -4) = *(undefined4 *)(param_1 + 0x24);
  local_18[1] = *(int *)(param_1 + 0x110);
  while( true ) {
    iVar5 = param_4;
    if (*(int *)(param_1 + 0x10c) <= param_4) {
      iVar5 = *(int *)(param_1 + 0x10c);
    }
    *(int *)((int)aiStack_3c + iVar3 + 0x10) = iVar5;
    *(int *)((int)aiStack_3c + iVar3 + 0xc) = param_3;
    *(undefined4 **)((int)aiStack_3c + iVar3 + 8) = puVar8 + 4;
    *(int *)((int)aiStack_3c + iVar3 + 4) = param_1;
    local_c = iVar5;
    *(undefined4 *)((int)aiStack_3c + iVar3) = 0x79d0b3;
    FUN_0079ce50();
    local_18[0] = iVar5 << 0x11;
    local_8 = 0;
    if (0 < local_18[0]) {
      do {
        iVar5 = (int)((local_8 & 0xffff) * 0xc) >> 0x10;
        psVar1 = (short *)((int)puVar8 + ((int)local_8 >> 0x10) * 2);
        uVar6 = ((int)(short)(&DAT_008379ec)[iVar5 * -4] * (int)psVar1[7] +
                 (int)(short)(&DAT_008379ee)[iVar5 * -4] * (int)psVar1[6] +
                 (int)(short)(&DAT_008379f0)[iVar5 * -4] * (int)psVar1[5] +
                 (int)(short)(&DAT_008379f2)[iVar5 * -4] * (int)psVar1[4] +
                 (int)(short)(&DAT_0083799a)[iVar5 * 4] * (int)psVar1[3] +
                 (int)(short)(&DAT_00837998)[iVar5 * 4] * (int)psVar1[2] +
                 (int)(short)(&DAT_00837996)[iVar5 * 4] * (int)psVar1[1] +
                 (int)(short)(&DAT_00837994)[iVar5 * 4] * (int)*psVar1 >> 0xe) + 1;
        uVar7 = uVar6 & 0xfffffffe;
        if ((int)uVar7 < 0xffff) {
          if ((int)uVar7 < -0x10000) {
            uVar4 = 0x8000;
          }
          else {
            uVar4 = (undefined2)((int)uVar6 >> 1);
          }
        }
        else {
          uVar4 = 0x7fff;
        }
        *param_2 = uVar4;
        local_8 = local_8 + local_18[1];
        param_2 = param_2 + 1;
        puVar8 = local_10;
      } while ((int)local_8 < local_18[0]);
      iVar5 = local_c;
    }
    param_3 = param_3 + iVar5 * 2;
    param_4 = param_4 - iVar5;
    if (param_4 < 1) break;
    puVar2 = puVar8 + iVar5;
    *puVar8 = *puVar2;
    puVar8[1] = puVar2[1];
    puVar8[2] = puVar2[2];
    puVar8[3] = puVar2[3];
  }
  puVar8 = puVar8 + iVar5;
  *local_1c = *puVar8;
  local_1c[1] = puVar8[1];
  local_1c[2] = puVar8[2];
  local_1c[3] = puVar8[3];
  return;
}

