
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0058dc30(int param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
            int param_7)

{
  int iVar1;
  float fVar2;
  undefined1 uVar3;
  byte bVar4;
  float fVar5;
  double dVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined1 *puVar14;
  int iVar15;
  int iVar16;
  float10 fVar17;
  int local_4d4;
  int local_4d0;
  int local_4cc;
  int local_4c4;
  undefined1 local_4ac [108];
  undefined1 local_440 [1076];
  undefined1 *local_c;
  
  fVar2 = (float)_DAT_0081ec30;
  param_2 = param_2 / fVar2;
  param_3 = param_3 / fVar2;
  param_5 = param_5 / fVar2;
  param_6 = param_6 / fVar2;
  if (0.0 <= param_2) {
    if (1.0 < param_2) {
      param_2 = 1.0;
    }
  }
  else {
    param_2 = 0.0;
  }
  if (0.0 <= param_3) {
    if (1.0 < param_3) {
      param_3 = 1.0;
    }
  }
  else {
    param_3 = 0.0;
  }
  if (param_4 < _DAT_007d652c) {
    param_4 = _DAT_007d652c;
  }
  if (0.0 <= param_5) {
    if (1.0 < param_5) {
      param_5 = 1.0;
    }
  }
  else {
    param_5 = 0.0;
  }
  if (0.0 <= param_6) {
    if (1.0 < param_6) {
      param_6 = 1.0;
    }
  }
  else {
    param_6 = 0.0;
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  if (param_6 < param_5) {
    param_5 = param_6;
  }
  if (DAT_00a37dc8 != 1) {
    fVar5 = _DAT_0085e57c - param_4;
    if (fVar5 < 0.0) {
      fVar5 = -fVar5;
    }
    if ((float)_DAT_007d6530 < fVar5) {
      local_4d4 = 0;
      do {
        fVar17 = (float10)FUN_0056d500((float)local_4d4 / fVar2,1.0 / param_4);
        dVar6 = _DAT_0081ec30;
        fVar2 = (float)(fVar17 * (float10)_DAT_0081ec30);
        if ((float10)fVar2 <= (float10)_DAT_0081ec30) {
          (&DAT_00ddaea0)[local_4d4] = (int)ROUND(fVar2);
        }
        else {
          (&DAT_00ddaea0)[local_4d4] = 0xff;
        }
        fVar2 = (float)dVar6;
        local_4d4 = local_4d4 + 1;
      } while (local_4d4 < 0x100);
      _DAT_0085e57c = param_4;
    }
    iVar1 = (int)ROUND(fVar2 * param_2);
    iVar13 = (int)ROUND(param_3 * (float)_DAT_0081ec30) - iVar1;
    iVar12 = (int)ROUND(param_6 * (float)_DAT_0081ec30) - (int)ROUND(param_5 * (float)_DAT_0081ec30)
    ;
    iVar7 = (int)ROUND(param_5 * (float)_DAT_0081ec30) * 0x100;
    iVar8 = FUN_00586970(param_1,1);
    if (iVar8 < 0) {
      return 0xffffffff;
    }
    iVar8 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
    local_4d4 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
    pbVar10 = *(byte **)(param_1 + 0x48c);
    puVar14 = *(undefined1 **)(param_1 + 0xd0c);
    iVar11 = *(int *)(param_1 + 0x488) + iVar8 * -4;
    iVar15 = *(int *)(param_1 + 0xd08) + iVar8 * -4;
    if (param_7 == 0) {
      do {
        local_4c4 = iVar8;
        do {
          iVar9 = (int)(((uint)*pbVar10 - iVar1) * 0x100) / iVar13;
          if (iVar9 < 0) {
            local_4d0 = DAT_00ddaea0;
          }
          else if (iVar9 < 0x100) {
            local_4d0 = (&DAT_00ddaea0)[iVar9];
          }
          else {
            local_4d0 = DAT_00ddb29c;
          }
          iVar9 = (int)(((uint)pbVar10[1] - iVar1) * 0x100) / iVar13;
          if (iVar9 < 0) {
            local_4cc = DAT_00ddaea0;
          }
          else if (iVar9 < 0x100) {
            local_4cc = (&DAT_00ddaea0)[iVar9];
          }
          else {
            local_4cc = DAT_00ddb29c;
          }
          iVar9 = (int)(((uint)pbVar10[2] - iVar1) * 0x100) / iVar13;
          if (iVar9 < 0) {
            iVar16 = DAT_00ddaea0;
          }
          else {
            iVar16 = DAT_00ddb29c;
            if (iVar9 < 0x100) {
              iVar16 = (&DAT_00ddaea0)[iVar9];
            }
          }
          *puVar14 = (char)((uint)(local_4d0 * iVar12 + iVar7) >> 8);
          puVar14[1] = (char)((uint)(local_4cc * iVar12 + iVar7) >> 8);
          puVar14[2] = (char)((uint)(iVar16 * iVar12 + iVar7) >> 8);
          puVar14[3] = pbVar10[3];
          pbVar10 = pbVar10 + 4;
          puVar14 = puVar14 + 4;
          local_4c4 = local_4c4 + -1;
        } while (local_4c4 != 0);
        pbVar10 = pbVar10 + iVar11;
        puVar14 = puVar14 + iVar15;
        local_4d4 = local_4d4 + -1;
      } while (local_4d4 != 0);
    }
    else {
      do {
        local_4c4 = iVar8;
        do {
          bVar4 = pbVar10[3];
          iVar9 = (int)(((uint)(byte)(&DAT_00a62a60)[CONCAT11(*pbVar10,bVar4)] - iVar1) * 0x100) /
                  iVar13;
          if (iVar9 < 0) {
            local_4d0 = DAT_00ddaea0;
          }
          else if (iVar9 < 0x100) {
            local_4d0 = (&DAT_00ddaea0)[iVar9];
          }
          else {
            local_4d0 = DAT_00ddb29c;
          }
          iVar9 = (int)(((uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar10[1],bVar4)] - iVar1) * 0x100) /
                  iVar13;
          if (iVar9 < 0) {
            local_4cc = DAT_00ddaea0;
          }
          else if (iVar9 < 0x100) {
            local_4cc = (&DAT_00ddaea0)[iVar9];
          }
          else {
            local_4cc = DAT_00ddb29c;
          }
          iVar9 = (int)(((uint)(byte)(&DAT_00a62a60)[CONCAT11(pbVar10[2],bVar4)] - iVar1) * 0x100) /
                  iVar13;
          if (iVar9 < 0) {
            iVar9 = DAT_00ddaea0;
          }
          else if (iVar9 < 0x100) {
            iVar9 = (&DAT_00ddaea0)[iVar9];
          }
          else {
            iVar9 = DAT_00ddb29c;
          }
          *puVar14 = (&DAT_00a52a60)
                     [(uint)bVar4 + (local_4d0 * iVar12 + iVar7 >> 8 & 0xffU) * 0x100];
          puVar14[1] = (&DAT_00a52a60)
                       [(uint)pbVar10[3] + (local_4cc * iVar12 + iVar7 >> 8 & 0xffU) * 0x100];
          puVar14[2] = (&DAT_00a52a60)
                       [(uint)pbVar10[3] + (iVar9 * iVar12 + iVar7 >> 8 & 0xffU) * 0x100];
          puVar14[3] = pbVar10[3];
          pbVar10 = pbVar10 + 4;
          puVar14 = puVar14 + 4;
          local_4c4 = local_4c4 + -1;
        } while (local_4c4 != 0);
        pbVar10 = pbVar10 + iVar11;
        puVar14 = puVar14 + iVar15;
        local_4d4 = local_4d4 + -1;
      } while (local_4d4 != 0);
    }
    FUN_00586b00();
    return 0;
  }
  if (DAT_00dda4e4 < 0) {
    FUN_005194a0(local_4ac,0x20,0,0);
    DAT_00dda4e4 = FUN_005243b0(local_4ac,0x100,1,0,0,0,0,0);
    FUN_00580830(DAT_00dda4e4,&DAT_00dda4e4);
    _DAT_00dda4e8 = _DAT_007d9be0;
  }
  else {
    fVar2 = _DAT_00dda4e8 - param_4;
    if (fVar2 < 0.0) {
      fVar2 = -fVar2;
    }
    if (fVar2 <= (float)_DAT_007d6530) goto LAB_0058df7d;
  }
  FUN_00546d10(0x100,1,local_440);
  if (local_c != (undefined1 *)0x0) {
    local_4d4 = 0;
    puVar14 = local_c;
    dVar6 = _DAT_0081ec30;
    do {
      fVar17 = (float10)FUN_0056d500((float)local_4d4 / (float)dVar6,1.0 / param_4);
      dVar6 = _DAT_0081ec30;
      fVar2 = (float)(fVar17 * (float10)_DAT_0081ec30);
      if ((float10)fVar2 <= (float10)_DAT_0081ec30) {
        local_4c4._0_1_ = (undefined1)(int)ROUND(fVar2);
        *puVar14 = (undefined1)local_4c4;
      }
      else {
        *puVar14 = 0xff;
      }
      uVar3 = *puVar14;
      local_4d4 = local_4d4 + 1;
      puVar14[1] = uVar3;
      puVar14[2] = uVar3;
      puVar14[3] = uVar3;
      puVar14 = puVar14 + 4;
    } while (local_4d4 < 0x100);
    FUN_00525f80(0,0,0,0,local_440,0,0,0,DAT_00dda4e4);
    _DAT_00dda4e8 = param_4;
    FUN_005421c0(local_440);
  }
LAB_0058df7d:
  FUN_005db980(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return 0;
}

