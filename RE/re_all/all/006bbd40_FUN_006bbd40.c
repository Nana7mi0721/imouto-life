
void FUN_006bbd40(int param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  byte bVar8;
  int *piVar9;
  int iVar10;
  byte bVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  undefined4 uVar15;
  int local_2c;
  uint *local_24;
  int local_20;
  
  piVar9 = (int *)(param_3 * 0x10 + (int)param_2);
  iVar1 = *(int *)(param_3 * 0x20 + 0x48 + param_1);
  iVar10 = (iVar1 * param_4 + *(int *)(param_3 * 0x20 + param_1 + 0x50)) * 4;
  param_2 = (int *)(*(int *)(param_1 + 0xd31c) + iVar10);
  puVar14 = (uint *)(*(int *)(param_1 + 0xa8) + iVar10);
  iVar2 = *(int *)(param_1 + 0xd114);
  iVar3 = piVar9[2];
  local_20 = param_4 * 8;
  local_2c = iVar3 * local_20 + piVar9[3];
  iVar10 = param_5 * 8;
  iVar4 = *piVar9;
  iVar5 = piVar9[1];
  if (local_20 < iVar10) {
    local_24 = puVar14;
    param_5 = local_20;
    do {
      param_5 = param_5 + 8;
      param_4 = 0;
      if (0 < iVar4) {
        bVar8 = ((iVar5 <= param_5) << 1 | local_20 < 1) * '\x02';
        iVar13 = local_2c;
        do {
          uVar12 = (uint)*(byte *)((*puVar14 >> 2 & 0xf) + 0x36b + param_1);
          bVar7 = iVar4 <= (8 - local_2c) + iVar13;
          iVar6 = *param_2;
          bVar11 = (bVar7 | bVar8) << 1 | param_4 < 1;
          if ((iVar2 < (int)((-(uint)(param_3 != 0) & 3) + 4)) ||
             (iVar6 <= (int)((-(uint)(param_3 != 0) & 0x780) + 0x780))) {
            if (iVar6 < 0x601) {
              if (iVar6 < 0x181) goto LAB_006bbf8d;
              uVar15 = 0;
            }
            else {
              uVar15 = 1;
            }
            FUN_006bc000(iVar13,iVar3,bVar11,*(undefined4 *)(param_1 + 0xd118 + uVar12 * 4),
                         *(undefined4 *)(param_1 + 0xd218 + uVar12 * 4),uVar15);
          }
          else {
            FUN_006bc000(iVar13,iVar3,bVar11,*(undefined4 *)(param_1 + 0xd118 + uVar12 * 4),
                         *(undefined4 *)(param_1 + 0xd218 + uVar12 * 4),1);
            if ((((param_3 != 0) || ((param_4 >= 1 && (0xf00 < param_2[-1])))) ||
                ((!bVar7 && (0xf00 < param_2[1])))) ||
               ((((bVar8 & 2) == 0 && (0xf00 < param_2[-iVar1])) ||
                (((bVar8 & 4) == 0 && (0xf00 < param_2[iVar1])))))) {
              FUN_006bc000(iVar13,iVar3,bVar11,*(undefined4 *)(param_1 + 0xd118 + uVar12 * 4),
                           *(undefined4 *)(param_1 + 0xd218 + uVar12 * 4),1);
              FUN_006bc000(iVar13,iVar3,bVar11,*(undefined4 *)(param_1 + 0xd118 + uVar12 * 4),
                           *(undefined4 *)(param_1 + 0xd218 + uVar12 * 4),1);
            }
          }
LAB_006bbf8d:
          param_4 = param_4 + 8;
          puVar14 = local_24 + 1;
          param_2 = param_2 + 1;
          iVar13 = iVar13 + 8;
          local_24 = puVar14;
        } while (param_4 < iVar4);
      }
      local_20 = local_20 + 8;
      local_2c = local_2c + iVar3 * 8;
    } while (local_20 < iVar10);
  }
  return;
}

