
void __thiscall
FUN_00791d30(int param_1,int *param_2,char param_3,undefined4 param_4,undefined4 param_5)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined **local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c [18];
  int iStack_4;
  
  *(char *)(param_1 + 0x3c) = param_3;
  if (param_3 == '\0') {
    local_58 = param_1 + 0x40;
    local_5c = &PTR_LAB_00837530;
    local_4c[3] = 0xdd5e0b6b;
    local_4c[4] = 0xdd5e0b6b;
    local_4c[5] = 0xdd5e0b6b;
    local_4c[6] = 0;
    local_50 = 0x5d5e0b6b;
    local_4c[0] = 0x5d5e0b6b;
    local_4c[1] = 0x5d5e0b6b;
    local_4c[2] = 0;
    (**(code **)(*param_2 + 4))(&local_5c,local_4c + 3,&local_50);
    iStack_4 = *(int *)(param_1 + 0x44);
    iVar7 = *(int *)(param_1 + 0x58);
    iVar3 = iStack_4 * 2;
    if ((iVar7 <= iVar3) && (iVar7 < iVar3)) {
      FUN_00793240(iVar3);
      iVar5 = iVar7 << 6;
      iVar7 = iVar3 - iVar7;
      do {
        puVar2 = (undefined4 *)(iVar5 + *(int *)(param_1 + 0x60));
        if (puVar2 != (undefined4 *)0x0) {
          puVar8 = local_4c;
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar2 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar2 = puVar2 + 1;
          }
        }
        iVar5 = iVar5 + 0x40;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    *(int *)(param_1 + 0x58) = iVar3;
  }
  else {
    FUN_00793ee0(param_4,param_5,0x3f800000);
    local_58 = param_1 + 0x68;
    local_5c = &PTR_LAB_00837538;
    local_54 = param_1;
    (**(code **)(*param_2 + 4))(&local_5c,param_1 + 4,param_1 + 0x14);
    iStack_4 = *(int *)(param_1 + 0x6c);
    iVar7 = *(int *)(param_1 + 0x80);
    iVar3 = iStack_4 * 2;
    if ((iVar7 <= iVar3) && (iVar7 < iVar3)) {
      FUN_00793310(iVar3);
      iVar5 = iVar7 << 4;
      iVar7 = iVar3 - iVar7;
      do {
        puVar2 = (undefined4 *)(*(int *)(param_1 + 0x88) + iVar5);
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = local_4c[0];
          puVar2[1] = local_4c[1];
          puVar2[2] = local_4c[2];
          puVar2[3] = local_4c[3];
        }
        iVar5 = iVar5 + 0x10;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    *(int *)(param_1 + 0x80) = iVar3;
  }
  FUN_00627ff0();
  *(undefined4 *)(param_1 + 0x38) = 0;
  FUN_00794110(0,iStack_4);
  if ((*(char *)(param_1 + 0x3c) != '\0') && (*(int *)(param_1 + 0x98) == 0)) {
    iVar7 = *(int *)(param_1 + 0x98);
    if (iVar7 == *(int *)(param_1 + 0x9c)) {
      iVar3 = iVar7 * 2;
      if (iVar7 == 0) {
        iVar3 = 1;
      }
      FUN_007933c0(iVar3);
    }
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
    puVar2 = (undefined4 *)(iVar7 * 0x20 + *(int *)(param_1 + 0xa0));
    if (puVar2 != (undefined4 *)0x0) {
      puVar8 = local_4c;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar2 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar2 = puVar2 + 1;
      }
    }
    puVar1 = *(undefined2 **)(param_1 + 0x88);
    puVar4 = (undefined2 *)(iVar7 * 0x20 + *(int *)(param_1 + 0xa0));
    *puVar4 = *puVar1;
    puVar4[1] = puVar1[1];
    puVar4[2] = puVar1[2];
    puVar4[3] = puVar1[3];
    puVar4[4] = puVar1[4];
    puVar4[5] = puVar1[5];
    *(undefined4 *)(puVar4 + 6) = 0;
    iVar7 = *(int *)(*(int *)(param_1 + 0x88) + 0xc);
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    else {
      iVar7 = 1;
    }
    *(int *)(puVar4 + 8) = iVar7;
  }
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x98);
  FUN_0060b970(0,*(undefined4 *)(param_1 + 0x6c));
  FUN_007932e0();
  FUN_00614ef0();
  FUN_0061ea60();
  return;
}

