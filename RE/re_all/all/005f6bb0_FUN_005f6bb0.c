
/* WARNING: Removing unreachable block (ram,0x005f6bde) */
/* WARNING: Removing unreachable block (ram,0x005f6bd2) */

undefined8 __fastcall FUN_005f6bb0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined4 local_8;
  
  local_8 = 0;
  uVar3 = ((uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
           (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
           (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1) |
           (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
           (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000) ^ 0x200000;
  if (((uVar3 == ((uint)((uVar3 & 0x4000) != 0) * 0x4000 | (uint)((uVar3 & 0x800) != 0) * 0x800 |
                  (uint)((uVar3 & 0x200) != 0) * 0x200 | (uint)((uVar3 & 0x100) != 0) * 0x100 |
                  (uint)((uVar3 & 0x80) != 0) * 0x80 | (uint)((uVar3 & 0x40) != 0) * 0x40 |
                  (uint)((uVar3 & 0x10) != 0) * 0x10 | (uint)((uVar3 & 4) != 0) * 4 |
                  (uint)((uVar3 & 1) != 0) | (uint)((uVar3 & 0x200000) != 0) * 0x200000 |
                 (uint)((uVar3 & 0x40000) != 0) * 0x40000)) &&
      (piVar1 = (int *)cpuid_basic_info(0), *piVar1 != 0)) &&
     (iVar2 = cpuid_Version_info(1), (*(uint *)(iVar2 + 8) & 0x800000) != 0)) {
    local_8 = 1;
  }
  return CONCAT44(param_2,local_8);
}

