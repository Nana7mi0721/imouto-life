
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4
FUN_0079add0(int param_1,undefined4 param_2,undefined4 *param_3,int *param_4,int param_5,
            undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int aiStackY_ec [2];
  undefined1 auStackY_e4 [4];
  undefined4 uStackY_e0;
  undefined1 auStackY_dc [4];
  int aiStackY_d8 [2];
  undefined1 auStackY_d0 [4];
  int aiStackY_cc [2];
  undefined4 *puStackY_c4;
  int aiStackY_c0 [2];
  undefined4 *apuStackY_b8 [2];
  undefined1 *puStackY_b0;
  undefined4 uStack_a0;
  undefined4 auStack_9c [33];
  undefined4 local_18;
  
  iVar3 = *(int *)(param_1 + 0x918);
  puStackY_b0 = (undefined1 *)&uStack_a0;
  local_18 = 0;
  if ((param_5 == 0) ||
     ((param_5 == 2 && (*(int *)(param_1 + 0x974 + *(int *)(param_1 + 0x954) * 4) == 1)))) {
    iVar8 = (iVar3 + 0xfU & 0xfffffff0) * -2;
    uVar4 = *(undefined4 *)(param_1 + 0x954);
    *(undefined4 *)((int)auStack_9c + iVar8 + -8) = param_6;
    *(int *)((int)apuStackY_b8 + iVar8 + 0x10) = param_5;
    *(undefined4 *)((int)apuStackY_b8 + iVar8 + 0xc) = uVar4;
    *(undefined4 *)((int)apuStackY_b8 + iVar8 + 8) = param_2;
    *(int *)((int)apuStackY_b8 + iVar8 + 4) = param_1;
    *(undefined4 *)((int)apuStackY_b8 + iVar8) = 0x79ae5d;
    FUN_0079b110();
    cVar1 = *(char *)(param_1 + 0xace);
    cVar2 = *(char *)(param_1 + 0xacd);
    *(undefined4 *)((int)apuStackY_b8 + iVar8) = *(undefined4 *)(param_1 + 0x918);
    *(int *)((int)aiStackY_c0 + iVar8 + 4) = (int)cVar1;
    *(int *)((int)aiStackY_c0 + iVar8) = (int)cVar2;
    *(int *)((int)aiStackY_cc + iVar8 + 8) = (int)&uStack_a0 + iVar8;
    *(undefined4 *)((int)aiStackY_cc + iVar8 + 4) = param_2;
    *(undefined4 *)((int)aiStackY_cc + iVar8) = 0x79ae7e;
    FUN_0079af50();
    *(undefined4 *)((int)aiStackY_cc + iVar8) = param_6;
    *(undefined4 **)(auStackY_d0 + iVar8) = &uStack_a0;
    *(int *)((int)aiStackY_d8 + iVar8 + 4) = param_1;
    *(undefined4 *)((int)aiStackY_d8 + iVar8) = 0x79ae89;
    FUN_0079e890();
    *(undefined4 *)((int)aiStackY_d8 + iVar8) = param_7;
    *(int *)(auStackY_dc + iVar8) = (int)&uStack_a0 + iVar8;
    *(undefined4 **)(auStackY_e4 + iVar8 + 4) = param_3;
    *(undefined4 **)(auStackY_e4 + iVar8) = &uStack_a0;
    *(int *)((int)aiStackY_ec + iVar8 + 4) = param_1;
    *(undefined4 *)((int)aiStackY_ec + iVar8) = 0x79ae99;
    FUN_0079ddc0();
    *(undefined4 *)((int)auStack_9c + iVar8 + -8) = param_7;
    *(undefined4 *)((int)apuStackY_b8 + iVar8 + 0x10) = 0;
    *(undefined4 **)((int)apuStackY_b8 + iVar8 + 0xc) = param_3;
    *(undefined4 **)((int)apuStackY_b8 + iVar8 + 8) = &uStack_a0;
    *(int *)((int)apuStackY_b8 + iVar8 + 4) = param_1;
    *(undefined4 *)((int)apuStackY_b8 + iVar8) = 0x79aeaa;
    FUN_0079b720();
    *(undefined4 *)(param_1 + 0x1040) = 0;
    *(int *)(param_1 + 0x1044) = (int)*(char *)(param_1 + 0xacd);
    *(undefined4 *)(param_1 + 0x948) = 0;
  }
  else {
    apuStackY_b8[1] = (undefined4 *)param_1;
    apuStackY_b8[0] = (undefined4 *)0x79ae29;
    FUN_0079b720();
  }
  iVar8 = *(int *)(param_1 + 0x920) - *(int *)(param_1 + 0x918);
  puStackY_b0 = (undefined1 *)0x79aeee;
  _memmove((void *)(param_1 + 0x544),(void *)(param_1 + 0x544 + *(int *)(param_1 + 0x918) * 2),
           iVar8 * 2);
  uVar5 = *(uint *)(param_1 + 0x918);
  puVar7 = param_3;
  puVar9 = (undefined4 *)(param_1 + 0x544 + iVar8 * 2);
  for (uVar6 = (uVar5 & 0x7fffffff) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar9 = puVar9 + 1;
  }
  for (iVar8 = (uVar5 & 1) << 1; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  apuStackY_b8[1] = param_3;
  aiStackY_c0[1] = param_1;
  aiStackY_c0[0] = 0x79af20;
  apuStackY_b8[0] = &uStack_a0;
  puStackY_b0 = (undefined1 *)iVar3;
  FUN_0079c620();
  puStackY_c4 = param_3;
  aiStackY_cc[1] = param_1;
  aiStackY_cc[0] = 0x79af28;
  aiStackY_c0[0] = iVar3;
  FUN_0079c3a0();
  *(undefined4 **)(param_1 + 0x904) = apuStackY_b8[*(int *)(param_1 + 0x914) + 5];
  *param_4 = iVar3;
  return 0;
}

