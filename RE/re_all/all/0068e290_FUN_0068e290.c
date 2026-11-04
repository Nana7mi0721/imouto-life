
void FUN_0068e290(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 byte *param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  int *piVar10;
  int local_220;
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  int local_20c;
  int local_200 [128];
  
  piVar10 = local_200;
  for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar10 = 0x7fffffff;
    piVar10 = piVar10 + 1;
  }
  local_218 = 0;
  if (0 < param_5) {
    do {
      local_220 = 4;
      bVar1 = *(byte *)(local_218 + param_6);
      uVar7 = (uint)bVar1;
      piVar10 = *(int **)(param_1 + 0x74);
      iVar2 = (param_2 - (uint)*(byte *)(uVar7 + *piVar10)) * 2;
      iVar4 = param_3 - (uint)*(byte *)(piVar10[1] + uVar7);
      iVar3 = iVar4 * 3;
      iVar5 = param_4 - (uint)*(byte *)(piVar10[2] + uVar7);
      iVar3 = iVar5 * iVar5 + iVar3 * iVar3 + iVar2 * iVar2;
      piVar10 = local_200;
      local_20c = (iVar2 + 8) * 0x20;
      pbVar8 = param_7;
      do {
        local_214 = 8;
        local_21c = iVar3;
        local_210 = (iVar4 * 9 + 0x12) * 8;
        do {
          iVar9 = 4;
          iVar2 = local_21c;
          iVar6 = (iVar5 + 4) * 0x10;
          do {
            if (iVar2 < *piVar10) {
              *piVar10 = iVar2;
              *pbVar8 = bVar1;
            }
            iVar2 = iVar2 + iVar6;
            iVar6 = iVar6 + 0x80;
            piVar10 = piVar10 + 1;
            pbVar8 = pbVar8 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          local_21c = local_21c + local_210;
          local_210 = local_210 + 0x120;
          local_214 = local_214 + -1;
        } while (local_214 != 0);
        iVar3 = iVar3 + local_20c;
        local_20c = local_20c + 0x200;
        local_220 = local_220 + -1;
      } while (local_220 != 0);
      local_218 = local_218 + 1;
    } while (local_218 < param_5);
  }
  return;
}

