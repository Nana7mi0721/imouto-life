
uint ** __thiscall FUN_00609050(int param_1,uint **param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *unaff_EBX;
  int *unaff_EBP;
  int *unaff_ESI;
  int *piVar4;
  uint **ppuVar5;
  bool bVar6;
  int **ppiStack_80;
  undefined4 ***pppuStack_7c;
  undefined4 ***pppuStack_78;
  uint **ppuStack_74;
  uint **ppuStack_70;
  uint **ppuStack_6c;
  undefined4 *puStack_68;
  undefined4 ***pppuStack_64;
  uint **ppuStack_60;
  int *piStack_5c;
  uint **ppuStack_58;
  uint uStack_54;
  uint uStack_50;
  uint *puStack_4c;
  uint **ppuStack_48;
  int *piStack_44;
  undefined1 *puStack_40;
  int *piStack_2c;
  int *piStack_28;
  undefined1 auStack_24 [4];
  undefined1 local_20 [4];
  undefined4 *puStack_1c;
  int local_18 [4];
  uint *apuStack_8 [2];
  
  piStack_44 = local_18;
  puStack_40 = local_20;
  ppuStack_48 = param_2;
  puStack_4c = (uint *)0x60906d;
  iVar1 = (*(code *)(*param_2)[5])();
  bVar6 = iVar1 == 0;
  puStack_4c = (uint *)(uint)(*(int *)(param_1 + 0x54) != 0);
  uStack_50 = -(uint)bVar6 & (uint)&piStack_2c;
  piStack_5c = *(int **)(*(int *)(param_1 + 0x90) + 0x98);
  uStack_54 = -(uint)bVar6 & (uint)auStack_24;
  ppuStack_58 = apuStack_8;
  ppuStack_60 = (undefined4 **)0x6090b0;
  iVar1 = (**(code **)(*piStack_5c + 0x1c))();
  if (iVar1 < 0) {
    return (uint **)0x0;
  }
  ppuStack_60 = &puStack_4c;
  pppuStack_64 = (undefined4 ***)&DAT_0085e904;
  puStack_68 = puStack_1c;
  ppuStack_6c = (uint **)0x6090d3;
  iVar1 = (**(code **)*puStack_1c)();
  if (iVar1 < 0) {
    if (bVar6) {
      ppuStack_6c = &puStack_4c;
      ppuStack_70 = (uint **)&piStack_44;
      ppuStack_74 = (uint **)piStack_28;
      pppuStack_78 = (undefined4 ***)0x609132;
      (**(code **)(*piStack_28 + 0x18))();
    }
    ppuStack_6c = param_2;
    ppuStack_70 = (uint **)0x609138;
    iVar1 = (*(code *)(*param_2)[7])();
    if (iVar1 == 0) {
      ppuStack_70 = (uint **)0x1;
      ppuStack_74 = (uint **)piStack_2c;
      pppuStack_78 = (undefined4 ***)0x609148;
      (**(code **)(*piStack_2c + 0x20))();
    }
    ppuStack_70 = param_2;
    ppuStack_74 = (uint **)0x60914e;
    iVar1 = (*(code *)(*param_2)[0xf])();
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x54) != 0)) {
      ppuStack_74 = (uint **)0x1;
      pppuStack_7c = (undefined4 ***)0x609165;
      (**(code **)(*unaff_EBX + 0x40))();
    }
    ppuStack_74 = param_2;
    pppuStack_78 = (undefined4 ***)0x60916b;
    iVar1 = (*(code *)(*param_2)[9])();
    if (iVar1 == 0) {
      pppuStack_78 = (undefined4 ***)0x1;
      ppiStack_80 = (int **)0x60917b;
      (**(code **)(*unaff_EBP + 0x28))();
    }
    pppuStack_78 = &ppuStack_60;
    pppuStack_7c = (undefined4 ***)param_2;
    ppiStack_80 = (int **)0x609186;
    iVar1 = (*(code *)(*param_2)[0xd])();
    if (iVar1 == 0) {
      pppuStack_7c = pppuStack_64;
      (**(code **)(*unaff_ESI + 0x38))();
      pppuStack_7c = pppuStack_64;
      ppiStack_80 = (int **)0x6091a3;
      FUN_00602330();
    }
  }
  else {
    ppuStack_6c = (uint **)(*(int *)(param_1 + 0x8c) + 0xa8);
    ppuStack_70 = (uint **)0x28;
    ppuStack_74 = ppuStack_58;
    pppuStack_78 = (undefined4 ***)0x6090f0;
    iVar1 = (*(code *)(*ppuStack_58)[0x14])();
    pppuStack_78 = pppuStack_64;
    pppuStack_7c = (undefined4 ***)0x6090fc;
    (*(code *)(*pppuStack_64)[2])();
    if (iVar1 < 0) {
      ppiStack_80 = (int **)0x60910e;
      (**(code **)(*unaff_ESI + 8))();
      return (uint **)0x0;
    }
  }
  pppuStack_7c = (undefined4 ***)&puStack_4c;
  ppiStack_80 = &piStack_44;
  *(undefined4 *)(param_1 + 0x54) = 0;
  iVar1 = (*(code *)(*param_2)[0x11])(param_2);
  if (iVar1 == 0) {
    (**(code **)(*piStack_44 + 0x48))(piStack_44,&uStack_50,&ppuStack_58);
  }
  ppuVar5 = param_2;
  piVar2 = (int *)(*(code *)(*param_2)[0xb])();
  piVar4 = piVar2;
  (*(code *)(*ppuStack_48)[0xc])(ppuStack_48);
  (*(code *)(*param_2)[3])(param_2,&pppuStack_7c);
  (*(code *)(*ppuStack_58)[3])(ppuStack_58,&ppiStack_80);
  for (uVar3 = (uint)piVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *ppuVar5 = (uint *)*piVar4;
    piVar4 = piVar4 + 1;
    ppuVar5 = ppuVar5 + 1;
  }
  for (uVar3 = (uint)piVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)ppuVar5 = (char)*piVar4;
    piVar4 = (int *)((int)piVar4 + 1);
    ppuVar5 = (uint **)((int)ppuVar5 + 1);
  }
  return ppuStack_60;
}

