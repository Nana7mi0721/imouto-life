
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006201c0(int param_1,int param_2)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float local_60;
  int local_58;
  int local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_40 [4];
  undefined1 local_30 [16];
  undefined4 local_20 [8];
  
  iVar3 = param_2;
  iVar6 = *(int *)(param_2 + 4);
  while (1 < iVar6) {
    local_58 = -1;
    local_54 = -1;
    iVar6 = *(int *)(iVar3 + 4);
    local_60 = 3.4028235e+38;
    iVar5 = 0;
    if (0 < iVar6) {
      do {
        iVar4 = iVar5 + 1;
        param_2 = iVar4;
        if (iVar4 < iVar6) {
          do {
            FUN_006219f0(*(undefined4 *)(*(int *)(iVar3 + 0xc) + iVar5 * 4),
                         *(undefined4 *)(*(int *)(iVar3 + 0xc) + param_2 * 4),local_20);
            puVar7 = local_20;
            puVar8 = local_40;
            for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar8 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar8 = puVar8 + 1;
            }
            FUN_005fc590(&local_50,local_30,local_40);
            fVar2 = (local_4c * local_50 + _DAT_00804108) * local_48 + local_4c + local_50;
            if (fVar2 < local_60) {
              local_54 = param_2;
              local_60 = fVar2;
              local_58 = iVar5;
            }
            param_2 = param_2 + 1;
          } while (param_2 < *(int *)(iVar3 + 4));
        }
        iVar6 = *(int *)(iVar3 + 4);
        iVar5 = iVar4;
      } while (iVar4 < iVar6);
    }
    iVar6 = *(int *)(*(int *)(iVar3 + 0xc) + local_58 * 4);
    iVar5 = *(int *)(*(int *)(iVar3 + 0xc) + local_54 * 4);
    iVar4 = *(int *)(param_1 + 4);
    if (iVar4 == 0) {
      iVar4 = FUN_00646b30(0x2c,0x10);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        FUN_0061ddb0();
      }
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    *(undefined4 *)(iVar4 + 0x20) = 0;
    *(undefined4 *)(iVar4 + 0x24) = 0;
    *(undefined4 *)(iVar4 + 0x28) = 0;
    FUN_006219f0(iVar6,iVar5,iVar4);
    *(int *)(iVar4 + 0x24) = iVar6;
    *(int *)(iVar4 + 0x28) = iVar5;
    *(int *)(iVar6 + 0x20) = iVar4;
    *(int *)(iVar5 + 0x20) = iVar4;
    *(int *)(*(int *)(iVar3 + 0xc) + local_58 * 4) = iVar4;
    iVar6 = *(int *)(iVar3 + 0xc);
    iVar5 = *(int *)(iVar3 + 4) + -1;
    uVar1 = *(undefined4 *)(iVar6 + local_54 * 4);
    *(undefined4 *)(iVar6 + local_54 * 4) = *(undefined4 *)(iVar6 + iVar5 * 4);
    *(undefined4 *)(*(int *)(iVar3 + 0xc) + iVar5 * 4) = uVar1;
    iVar6 = *(int *)(iVar3 + 4) + -1;
    *(int *)(iVar3 + 4) = iVar6;
  }
  return;
}

