
void __thiscall FUN_0062aa90(float param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  float10 fVar7;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  int local_a8;
  float local_a4;
  float local_a0;
  undefined1 *local_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  undefined4 uStack_8c;
  undefined1 auStack_88 [4];
  undefined1 auStack_84 [4];
  undefined1 auStack_80 [16];
  undefined4 local_70;
  undefined4 local_6c [11];
  undefined4 local_40;
  undefined4 local_3c [11];
  undefined1 auStack_10 [16];
  
  iVar1 = param_2 + 0x40;
  local_a4 = (float)((int)local_6c + (0x2c - iVar1));
  local_9c = auStack_80 + -iVar1 + 0x10;
  local_a0 = (float)((int)local_6c - iVar1);
  local_bc = (float)((int)local_3c - iVar1);
  puVar4 = (undefined4 *)(param_2 + 0x44);
  iVar6 = 0;
  while( true ) {
    puVar5 = puVar4 + 4;
    *(undefined4 *)(auStack_80 + iVar6 + 0x10) = *(undefined4 *)(iVar6 + param_2);
    *(undefined4 *)((int)local_6c + iVar6 + 0x2c) = puVar4[-1];
    *(undefined4 *)(auStack_80 + -iVar1 + (int)puVar5) =
         *(undefined4 *)((param_2 - iVar1) + -0x10 + (int)puVar5);
    *(undefined4 *)((int)puVar4 + (int)local_a4) = *puVar4;
    *(undefined4 *)((int)puVar4 + (int)local_a0) = *(undefined4 *)(iVar6 + 8 + param_2);
    *(undefined4 *)((int)puVar4 + (int)local_bc) = puVar4[1];
    if (0x2f < iVar6 + 0x10) break;
    puVar4 = puVar5;
    iVar6 = iVar6 + 0x10;
  }
  piVar2 = *(int **)((int)param_1 + 8);
  local_b4 = (float)piVar2[7];
  local_b0 = (float)piVar2[8];
  local_ac = (float)piVar2[9];
  local_a8 = piVar2[10];
  local_b8 = param_1;
  fVar7 = (float10)(**(code **)(*piVar2 + 0x28))();
  local_bc = (float)fVar7;
  fVar7 = (float10)(**(code **)(*piVar2 + 0x28))();
  local_b8 = (float)fVar7;
  fVar7 = (float10)(**(code **)(*piVar2 + 0x28))();
  fVar3 = local_b0 + local_b8;
  local_b8 = local_ac + local_bc + local_ac + local_bc;
  local_bc = fVar3 + fVar3;
  local_a0 = (float)(fVar7 + (float10)local_b4 + fVar7 + (float10)local_b4);
  FUN_005fc500(&local_a0,&local_bc,&local_b8);
  piVar2 = *(int **)((int)param_1 + 4);
  local_b4 = (float)piVar2[7];
  local_b0 = (float)piVar2[8];
  local_ac = (float)piVar2[9];
  local_a8 = piVar2[10];
  fVar7 = (float10)(**(code **)(*piVar2 + 0x28))();
  local_9c = (undefined1 *)(float)fVar7;
  fVar7 = (float10)(**(code **)(*piVar2 + 0x28))();
  local_a4 = (float)fVar7;
  fVar7 = (float10)(**(code **)(*piVar2 + 0x28))();
  local_b0 = local_b0 + local_a4;
  local_ac = local_ac + (float)local_9c;
  fStack_98 = (float)(fVar7 + (float10)local_b4 + fVar7 + (float10)local_b4);
  fStack_94 = local_b0 + local_b0;
  fStack_90 = local_ac + local_ac;
  uStack_8c = 0;
  FUN_00628da0(param_2 + 0x30,&local_70,&fStack_98,param_2 + 0x70,&local_40,auStack_80,auStack_10,
               auStack_88,auStack_84,4,0,0,param_3);
  return;
}

