
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0078bef0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float unaff_ESI;
  float unaff_EDI;
  undefined1 *puStack_3c;
  undefined1 local_30 [4];
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  undefined1 local_20 [8];
  float fStack_18;
  float fStack_14;
  
  puStack_3c = local_30;
  (**(code **)(**(int **)(param_2 + 0xc0) + 4))(param_2 + 4,local_20);
  fStack_2c = fStack_2c - DAT_00a06254;
  fStack_18 = DAT_00a06254;
  fStack_14 = DAT_00a06254;
  fStack_28 = fStack_28 - DAT_00a06254;
  fStack_24 = fStack_24 - DAT_00a06254;
  puStack_3c = (undefined1 *)(DAT_00a06254 + (float)puStack_3c);
  if (((*(byte *)(param_2 + 200) & 1) != 0) ||
     (fVar2 = (unaff_EDI + DAT_00a06254) - fStack_28, fVar1 = (unaff_ESI + DAT_00a06254) - fStack_24
     , ((float)puStack_3c - fStack_2c) * ((float)puStack_3c - fStack_2c) +
       fVar2 * fVar2 + fVar1 * fVar1 < _DAT_008373ec)) {
    (**(code **)(**(int **)(param_1 + 0x4c) + 0xc))
              (*(undefined4 *)(param_2 + 0xbc),&fStack_2c,&puStack_3c,
               *(undefined4 *)(param_1 + 0x18));
  }
  else {
    FUN_006105d0(5);
    if ((DAT_00a0f6f8 != '\0') && (*(int *)(param_1 + 0x50) != 0)) {
      DAT_00a0f6f8 = 0;
      (**(code **)(**(int **)(param_1 + 0x50) + 0x20))
                ("Overflow in AABB, object removed from simulation");
      (**(code **)(**(int **)(param_1 + 0x50) + 0x20))
                ("If you D_can reproduce this, please email bugs@continuousphysics.com\n");
      (**(code **)(**(int **)(param_1 + 0x50) + 0x20))
                ("Please include above information, your Platform, version of OS.\n");
      (**(code **)(**(int **)(param_1 + 0x50) + 0x20))("Thanks.\n");
      return;
    }
  }
  return;
}

