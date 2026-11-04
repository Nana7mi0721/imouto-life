
undefined4 FUN_0058e970(int param_1,undefined4 param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 *puVar6;
  int local_850;
  int local_84c;
  int local_848;
  int local_844;
  byte abStack_840 [1020];
  undefined4 local_444;
  undefined1 local_440 [1076];
  int local_c;
  
  if (DAT_00a37dc8 == 1) {
    FUN_005dba70(param_1,param_2,param_3,param_4);
    return 0;
  }
  iVar2 = FUN_00515880(param_2,&local_850,&local_848);
  if ((-1 < iVar2) && (iVar2 = FUN_005866a0(param_2,local_440,0), -1 < iVar2)) {
    uVar3 = 0;
    if (param_3 == 0) {
      uVar5 = 0;
      do {
        *(undefined4 *)(abStack_840 + uVar3 * 4) = *(undefined4 *)(local_c + (uVar5 >> 8) * 4);
        uVar3 = uVar3 + 1;
        uVar5 = uVar5 + local_850;
      } while (uVar3 < 0x100);
    }
    else {
      puVar6 = &local_444;
      iVar2 = 0x100;
      do {
        *puVar6 = *(undefined4 *)(local_c + (uVar3 >> 8) * 4);
        uVar3 = uVar3 + local_850;
        puVar6 = puVar6 + -1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (param_4 != 0) {
      uVar3 = 0;
      do {
        bVar1 = abStack_840[uVar3 * 4 + 3];
        abStack_840[uVar3 * 4] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4],bVar1)];
        abStack_840[uVar3 * 4 + 1] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 1],bVar1)];
        abStack_840[uVar3 * 4 + 2] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 2],bVar1)];
        bVar1 = abStack_840[uVar3 * 4 + 7];
        abStack_840[uVar3 * 4 + 4] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 4],bVar1)];
        abStack_840[uVar3 * 4 + 5] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 5],bVar1)];
        abStack_840[uVar3 * 4 + 6] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 6],bVar1)];
        bVar1 = abStack_840[uVar3 * 4 + 0xb];
        abStack_840[uVar3 * 4 + 8] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 8],bVar1)];
        abStack_840[uVar3 * 4 + 9] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 9],bVar1)];
        abStack_840[uVar3 * 4 + 10] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 10],bVar1)];
        bVar1 = abStack_840[uVar3 * 4 + 0xf];
        abStack_840[uVar3 * 4 + 0xc] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 0xc],bVar1)]
        ;
        abStack_840[uVar3 * 4 + 0xd] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 0xd],bVar1)]
        ;
        abStack_840[uVar3 * 4 + 0xe] = (&DAT_00a52a60)[CONCAT11(abStack_840[uVar3 * 4 + 0xe],bVar1)]
        ;
        uVar3 = uVar3 + 4;
      } while (uVar3 < 0x100);
    }
    FUN_005421c0(local_440);
    iVar2 = FUN_00586970(param_1,1);
    if (-1 < iVar2) {
      local_848 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
      iVar2 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
      pbVar4 = *(byte **)(param_1 + 0x48c);
      puVar6 = *(undefined4 **)(param_1 + 0xd0c);
      local_844 = *(int *)(param_1 + 0x488) + local_848 * -4;
      local_84c = *(int *)(param_1 + 0xd08) + local_848 * -4;
      if (param_4 == 0) {
        do {
          local_850 = local_848;
          do {
            *puVar6 = *(undefined4 *)
                       (abStack_840 +
                       ((int)((uint)pbVar4[1] * 0x964 + (uint)pbVar4[2] * 0x4c8 +
                             (uint)*pbVar4 * 0x1d2) >> 0xc) * 4);
            pbVar4 = pbVar4 + 4;
            puVar6 = puVar6 + 1;
            local_850 = local_850 + -1;
          } while (local_850 != 0);
          pbVar4 = pbVar4 + local_844;
          puVar6 = (undefined4 *)((int)puVar6 + local_84c);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        FUN_00586b00();
        return 0;
      }
      do {
        local_850 = local_848;
        do {
          bVar1 = pbVar4[3];
          *puVar6 = *(undefined4 *)
                     (abStack_840 +
                     ((int)((uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar4[1],bVar1)] * 0x964 +
                            (uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar4[2],bVar1)] * 0x4c8 +
                           (uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar4,bVar1)] * 0x1d2) >> 0xc) * 4
                     );
          pbVar4 = pbVar4 + 4;
          puVar6 = puVar6 + 1;
          local_850 = local_850 + -1;
        } while (local_850 != 0);
        pbVar4 = pbVar4 + local_844;
        puVar6 = (undefined4 *)((int)puVar6 + local_84c);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      FUN_00586b00();
      return 0;
    }
  }
  return 0xffffffff;
}

