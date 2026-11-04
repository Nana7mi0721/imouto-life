
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0063f4c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  undefined4 *puVar8;
  float *pfVar9;
  char *pcVar10;
  float10 fVar11;
  float10 fVar12;
  float local_94;
  int local_90;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 local_70 [48];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [48];
  
  uVar3 = FUN_005fc8d0(&local_80,param_1 + 0x84);
  uVar4 = FUN_005fc790(local_30,param_3,param_1 + 0x54,uVar3);
  FUN_005fcd10(uVar4,uVar3);
  FUN_005fc5f0(local_70);
  *(undefined4 *)(param_1 + 0x434) = local_40;
  *(undefined4 *)(param_1 + 0x438) = local_3c;
  *(undefined4 *)(param_1 + 0x43c) = local_38;
  *(undefined4 *)(param_1 + 0x440) = local_34;
  uVar3 = FUN_005fc8d0(&local_80,param_1 + 0xc4);
  uVar4 = FUN_005fc790(local_30,param_4,param_1 + 0x94,uVar3);
  FUN_005fcd10(uVar4,uVar3);
  FUN_0061ce50(local_70);
  FUN_0063fd20();
  FUN_0063dfa0();
  pfVar9 = (float *)(param_1 + 0x358);
  pfVar7 = (float *)(param_1 + 0x484);
  local_90 = 3;
  do {
    fVar1 = *pfVar9;
    fVar2 = pfVar9[1];
    local_94 = *pfVar7;
    if (fVar1 < fVar2) {
      if (fVar1 <= local_94) {
        if (fVar2 < local_94) {
          fVar11 = (float10)FUN_005fca00(local_94 - fVar2);
          fVar12 = (float10)FUN_005fca00(local_94 - fVar1);
          if (ABS(fVar12) < (float10)(float)fVar11) {
            local_94 = local_94 - _DAT_00802ec0;
          }
        }
      }
      else {
        fVar11 = (float10)FUN_005fca00(fVar1 - local_94);
        fVar12 = (float10)FUN_005fca00(fVar2 - local_94);
        if (ABS(fVar12) <= (float10)(float)fVar11) {
          local_94 = local_94 + _DAT_00802ec0;
        }
      }
    }
    pfVar9[0xb] = local_94;
    FUN_0063d590(local_94);
    pfVar7 = pfVar7 + 1;
    pfVar9 = pfVar9 + 0xe;
    local_90 = local_90 + -1;
  } while (local_90 != 0);
  iVar5 = FUN_0063f770(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  puVar8 = (undefined4 *)(param_1 + 0x494);
  pcVar10 = (char *)(param_1 + 0x37c);
  local_90 = 3;
  do {
    if ((*(int *)(pcVar10 + 0xc) != 0) || (*pcVar10 != '\0')) {
      local_80 = *puVar8;
      local_7c = puVar8[1];
      local_78 = puVar8[2];
      local_74 = puVar8[3];
      iVar6 = FUN_0063ff80(pcVar10 + -0x24,param_3,param_4,param_5,param_6,param_7,param_8,param_2,
                           iVar5,&local_80,1);
      iVar5 = iVar5 + iVar6;
    }
    puVar8 = puVar8 + 4;
    pcVar10 = pcVar10 + 0x38;
    local_90 = local_90 + -1;
  } while (local_90 != 0);
  return;
}

