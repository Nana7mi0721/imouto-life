
void __thiscall FUN_0060d8f0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  int local_34;
  int local_30;
  int local_28;
  
  do {
    local_30 = param_3;
    piVar9 = (int *)(((param_3 + param_4) / 2) * 0x10 + *(int *)(param_1 + 0xc));
    iVar1 = *piVar9;
    iVar2 = piVar9[1];
    uVar3 = piVar9[2];
    local_34 = param_4;
    do {
      iVar4 = *(int *)(param_1 + 0xc);
      piVar9 = (int *)(local_30 * 0x10 + iVar4);
      while( true ) {
        iVar16 = *piVar9;
        if (iVar16 == 0) {
          local_28 = -1;
        }
        else {
          local_28 = *(int *)(iVar16 + 0xc);
        }
        if (iVar1 == 0) {
          iVar12 = -1;
        }
        else {
          iVar12 = *(int *)(iVar1 + 0xc);
        }
        iVar10 = piVar9[1];
        if (iVar10 == 0) {
          iVar13 = -1;
        }
        else {
          iVar13 = *(int *)(iVar10 + 0xc);
        }
        if (iVar2 == 0) {
          iVar15 = -1;
        }
        else {
          iVar15 = *(int *)(iVar2 + 0xc);
        }
        if ((local_28 <= iVar12) &&
           ((iVar16 != iVar1 ||
            ((iVar13 <= iVar15 &&
             (((iVar16 != iVar1 || (iVar10 != iVar2)) || ((uint)piVar9[2] <= uVar3)))))))) break;
        local_30 = local_30 + 1;
        piVar9 = piVar9 + 4;
      }
      piVar9 = (int *)(local_34 * 0x10 + iVar4);
      while( true ) {
        if (iVar1 == 0) {
          local_28 = -1;
        }
        else {
          local_28 = *(int *)(iVar1 + 0xc);
        }
        iVar16 = *piVar9;
        if (iVar16 == 0) {
          iVar12 = -1;
        }
        else {
          iVar12 = *(int *)(iVar16 + 0xc);
        }
        if (iVar2 == 0) {
          iVar10 = -1;
        }
        else {
          iVar10 = *(int *)(iVar2 + 0xc);
        }
        iVar13 = piVar9[1];
        if (iVar13 == 0) {
          iVar15 = -1;
        }
        else {
          iVar15 = *(int *)(iVar13 + 0xc);
        }
        if ((local_28 <= iVar12) &&
           ((iVar1 != iVar16 ||
            ((iVar10 <= iVar15 &&
             (((iVar1 != iVar16 || (iVar2 != iVar13)) || (uVar3 <= (uint)piVar9[2])))))))) break;
        local_34 = local_34 + -1;
        piVar9 = piVar9 + -4;
      }
      if (local_34 < local_30) break;
      iVar16 = local_30 * 0x10;
      uVar5 = *(undefined4 *)(iVar16 + 0xc + iVar4);
      uVar6 = *(undefined4 *)(iVar16 + iVar4);
      uVar7 = *(undefined4 *)(iVar16 + 4 + iVar4);
      puVar11 = (undefined4 *)(iVar16 + iVar4);
      puVar14 = (undefined4 *)(iVar4 + local_34 * 0x10);
      uVar8 = puVar11[2];
      *puVar11 = *puVar14;
      puVar11[1] = puVar14[1];
      puVar11[2] = puVar14[2];
      puVar11[3] = puVar14[3];
      puVar11 = (undefined4 *)(*(int *)(param_1 + 0xc) + local_34 * 0x10);
      *puVar11 = uVar6;
      puVar11[1] = uVar7;
      puVar11[2] = uVar8;
      puVar11[3] = uVar5;
      local_30 = local_30 + 1;
      local_34 = local_34 + -1;
    } while (local_30 <= local_34);
    if (param_3 < local_34) {
      FUN_0060d8f0(param_2,param_3,local_34);
    }
    if (param_4 <= local_30) {
      return;
    }
    param_3 = local_30;
  } while( true );
}

