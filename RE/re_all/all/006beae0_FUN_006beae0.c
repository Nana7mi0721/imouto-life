
int FUN_006beae0(int param_1,int param_2,char param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  int local_b4;
  undefined2 local_b0;
  short *local_ac;
  int local_a8;
  int local_a0;
  byte abStack_8d [37];
  byte local_68 [36];
  short local_44 [34];
  
  local_68[0] = param_3 - 1;
  iVar10 = 0;
  abStack_8d[1] = 0;
  local_b4 = 0;
  local_a8 = 0;
LAB_006beb14:
  iVar6 = FUN_006bed70();
  local_ac = local_44 + local_a8;
  *local_ac = (short)iVar10;
  iVar7 = FUN_006bee20();
  iVar10 = iVar10 + iVar7;
  if (param_1 != 0) {
    sVar4 = *local_ac;
    *(short *)(param_1 + sVar4 * 2) = (short)iVar6;
    *local_ac = sVar4 + 1;
  }
  local_a0 = iVar6;
  do {
    uVar8 = (uint)local_68[local_a8];
    if (local_b4 <= (int)uVar8) {
      bVar1 = abStack_8d[local_a8 + 1];
      iVar7 = (uint)bVar1 + iVar6;
      pbVar11 = (byte *)(param_2 + 1 + local_b4 * 2);
      do {
        bVar2 = *pbVar11;
        if (iVar7 < (int)(uint)bVar2) break;
        if (param_1 != 0) {
          iVar9 = 1 << ((bVar1 - bVar2) + (char)iVar6 & 0x1f);
          bVar3 = pbVar11[-1];
          if (0 < iVar9) {
            do {
              sVar4 = *local_ac;
              iVar9 = iVar9 + -1;
              *(ushort *)(param_1 + sVar4 * 2) =
                   -(((ushort)bVar2 - (ushort)bVar1) * 0x100 | (ushort)bVar3);
              *local_ac = sVar4 + 1;
            } while (iVar9 != 0);
            iVar6 = local_a0;
          }
        }
        local_b4 = local_b4 + 1;
        pbVar11 = pbVar11 + 2;
      } while (local_b4 <= (int)uVar8);
      if (local_b4 <= (int)uVar8) break;
    }
    iVar7 = local_a8 + -1;
    local_ac = local_ac + -1;
    if (0 < local_a8) {
      iVar6 = (uint)abStack_8d[local_a8 + 1] - (uint)abStack_8d[local_a8];
      local_a0 = iVar6;
    }
    local_a8 = iVar7;
    if (iVar7 < 0) {
      return iVar10;
    }
  } while( true );
  abStack_8d[local_a8 + 2] = abStack_8d[local_a8 + 1] + (char)iVar6;
  if (param_1 != 0) {
    sVar4 = local_44[local_a8];
    local_b0 = (undefined2)iVar10;
    *(undefined2 *)(param_1 + sVar4 * 2) = local_b0;
    local_44[local_a8] = sVar4 + 1;
  }
  cVar5 = FUN_006bed20();
  local_68[local_a8 + 1] = cVar5 + (char)local_b4 + -1;
  if (local_a8 + 1 < 0) {
    return iVar10;
  }
  local_a8 = local_a8 + 1;
  goto LAB_006beb14;
}

