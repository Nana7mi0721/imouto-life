
undefined4 FUN_006a9720(undefined4 *param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  longlong lVar10;
  undefined4 local_10;
  undefined4 local_c;
  undefined8 local_8;
  
  puVar7 = param_1;
  puVar6 = param_1 + 0x12;
  uVar3 = *(undefined4 *)param_1[0xf];
  uVar4 = ((undefined4 *)param_1[0xf])[1];
  uVar5 = param_1[0x72];
  local_10 = 0xffffffff;
  local_c = 0xffffffff;
  param_1 = (undefined4 *)uVar5;
  local_8 = FUN_006a9b00(puVar7,*puVar6);
  if (((code *)puVar7[0xb1] == (code *)0x0) || (puVar7[0xb3] == 0)) {
    puVar7[4] = 0xffffffff;
    puVar7[2] = 0xffffffff;
    puVar7[5] = 0xffffffff;
    puVar7[3] = 0xffffffff;
  }
  else {
    (*(code *)puVar7[0xb1])(*puVar7,0,0,2);
    iVar8 = (*(code *)puVar7[0xb3])(*puVar7);
    puVar7[4] = iVar8;
    puVar7[5] = iVar8 >> 0x1f;
    puVar7[2] = puVar7[4];
    puVar7[3] = iVar8 >> 0x1f;
  }
  if ((puVar7[4] & puVar7[5]) == 0xffffffff) {
    return 0xffffff7d;
  }
  lVar10 = FUN_006a98a0(puVar7,puVar7[4],puVar7[5],puVar7[0x10] + 8,
                        *(undefined4 *)(puVar7[0x10] + 4),&param_1,&local_10);
  uVar9 = (undefined4)lVar10;
  if ((0xffffffff < lVar10) || (-1 < lVar10)) {
    iVar8 = FUN_006a9c20(puVar7,0,0,uVar3,uVar4,lVar10,local_10,local_c,param_1,puVar7[0x10] + 8,
                         *(undefined4 *)(puVar7[0x10] + 4),0);
    if (iVar8 < 0) {
      return 0xffffff80;
    }
    puVar6 = (undefined4 *)puVar7[0xe];
    *puVar6 = 0;
    puVar6[1] = 0;
    *(undefined4 *)puVar7[0x10] = uVar5;
    puVar6 = (undefined4 *)puVar7[0xf];
    *puVar6 = uVar3;
    puVar6[1] = uVar4;
    *(undefined8 *)puVar7[0x11] = local_8;
    iVar8 = puVar7[0x11];
    puVar1 = (uint *)(iVar8 + 8);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 - (uint)local_8;
    *(uint *)(iVar8 + 0xc) = (*(int *)(iVar8 + 0xc) - local_8._4_4_) - (uint)(uVar2 < (uint)local_8)
    ;
    iVar8 = puVar7[0x11];
    if ((*(int *)(iVar8 + 0xc) < 1) && (*(int *)(iVar8 + 0xc) < 0)) {
      *(undefined4 *)(iVar8 + 8) = 0;
      *(undefined4 *)(iVar8 + 0xc) = 0;
    }
    uVar9 = FUN_006aa1b0(puVar7,uVar3,uVar4);
  }
  return uVar9;
}

