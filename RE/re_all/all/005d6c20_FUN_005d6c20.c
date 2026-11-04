
void __fastcall FUN_005d6c20(undefined4 param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  byte bVar5;
  int extraout_EDX;
  int unaff_EDI;
  
  uVar3 = *(uint *)(param_2 + 0x20);
  if (uVar3 == 0) {
    bVar5 = 0xff;
  }
  else {
    cVar4 = FUN_005d6890();
    bVar5 = cVar4 - 1;
    param_2 = extraout_EDX;
  }
  *(byte *)(param_2 + 0x17) = bVar5;
  *(char *)(param_2 + 0x18) = (char)(((1 << (bVar5 & 0x1f)) - 1U & uVar3) >> (bVar5 - 5 & 0x1f));
  *(uint *)(unaff_EDI + 0x294) = *(uint *)(unaff_EDI + 0x294) | 1 << (bVar5 & 0x1f);
  puVar1 = (uint *)(unaff_EDI + 0x298 + (uint)*(byte *)(param_2 + 0x17) * 4);
  *puVar1 = *puVar1 | 1 << (*(byte *)(param_2 + 0x18) & 0x1f);
  piVar2 = (int *)(unaff_EDI + 0x318 +
                  ((uint)*(byte *)(param_2 + 0x17) * 0x20 + (uint)*(byte *)(param_2 + 0x18)) * 4);
  *(undefined4 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x3c) = *piVar2;
  *piVar2 = param_2;
  if (*(int *)(param_2 + 0x3c) == 0) {
    *(int *)(unaff_EDI + 0x318 +
            ((uint)*(byte *)(param_2 + 0x17) * 0x20 + (uint)*(byte *)(param_2 + 0x18)) * 4) =
         param_2;
    return;
  }
  *(int *)(*(int *)(param_2 + 0x3c) + 0x38) = param_2;
  return;
}

