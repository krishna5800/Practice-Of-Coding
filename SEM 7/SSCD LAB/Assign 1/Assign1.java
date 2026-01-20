import java.io.*;
import java.util.*;

public class Assign1 
{

    // ===== Classes =====
    static class Opcode 
    {
        String mnemonic, type;
        int opcode;

        Opcode(String m, String t, int op) 
        {
            mnemonic = m;
            type = t;
            opcode = op;
        }
    }

    static class Symbol 
    {
        String name;
        int address;

        Symbol(String n, int addr) 
        {
            name = n;
            address = addr;
        }
    }

    static class ICLine 
    {
        int lc;
        String ic;

        ICLine(int lc, String ic) 
        {
            this.lc = lc;
            this.ic = ic;
        }
    }

    // ===== Tables =====
    static Map<String, Opcode> OPTAB = new LinkedHashMap<>();
    static Map<String, Integer> REGTAB = new LinkedHashMap<>();
    static Map<String, Symbol> SYMTAB = new LinkedHashMap<>();
    static List<ICLine> ICTAB = new ArrayList<>();

    static int LC = 0;

    // ===== Initialize Tables =====
    static void initTables() 
    {

        // OPTAB
        OPTAB.put("START", new Opcode("START", "AD", 1));
        OPTAB.put("END", new Opcode("END", "AD", 2));

        OPTAB.put("ADD", new Opcode("ADD", "IS", 1));
        OPTAB.put("SUB", new Opcode("SUB", "IS", 2));

        OPTAB.put("DS", new Opcode("DS", "DL", 1));
        OPTAB.put("DC", new Opcode("DC", "DL", 2));

        // REGTAB
        REGTAB.put("AREG", 1);
        REGTAB.put("BREG", 2);
        REGTAB.put("CREG", 3);
        REGTAB.put("DREG", 4);
    }

    // ===== PASS 1 =====
    static void pass1(String fileName) throws Exception 
    {
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        String line;

        while ((line = br.readLine()) != null) 
        {

            if (line.trim().isEmpty())
                continue;

            String[] tokens = line.trim().split("\\s+");
            int index = 0;

            String label = null;
            String mnemonic;
            String op1 = null, op2 = null;

            if (!OPTAB.containsKey(tokens[index])) 
            {
                label = tokens[index++];
            }

            mnemonic = tokens[index++];

            if (index < tokens.length) op1 = tokens[index++];
            if (index < tokens.length) op2 = tokens[index];

            Opcode op = OPTAB.get(mnemonic);

            // START
            if (mnemonic.equals("START")) 
            {
                LC = (op1 != null) ? Integer.parseInt(op1) : 0;
                ICTAB.add(new ICLine(-1, "(AD,01) (C," + LC + ")"));
                continue;
            }

            // END
            if (mnemonic.equals("END")) 
            {
                ICTAB.add(new ICLine(-1, "(AD,02)"));
                break;
            }

            // Add symbol
            if (label != null && !SYMTAB.containsKey(label)) 
            {
                SYMTAB.put(label, new Symbol(label, LC));
            }

            // DL Statements
            if (op.type.equals("DL")) 
            {
                if (mnemonic.equals("DS")) 
                {
                    ICTAB.add(new ICLine(LC, "(DL,01) (C," + op1 + ")"));
                    LC += Integer.parseInt(op1);
                } else if (mnemonic.equals("DC")) 
                {
                    ICTAB.add(new ICLine(LC, "(DL,02) (C," + op1 + ")"));
                    LC++;
                }
                continue;
            }

            // IS Statements
            String ic = "(IS," + String.format("%02d", op.opcode) + ") ";

            if (REGTAB.containsKey(op1))
                ic += "(R," + REGTAB.get(op1) + ") ";

            if (op2 != null)
                ic += "(S," + op2 + ")";

            ICTAB.add(new ICLine(LC, ic));
            LC++;
        }
        br.close();
    }

    // ===== Display Tables =====
    static void displayOPTAB() 
    {
        System.out.println("\nOPCODE TABLE");
        System.out.println("Mnemonic\tType\tOpcode");
        for (Opcode o : OPTAB.values()) 
        {
            System.out.println(o.mnemonic + "\t\t" + o.type + "\t" + o.opcode);
        }
    }

    static void displayREGTAB() 
    {
        System.out.println("\nREGISTER TABLE");
        System.out.println("Register\tCode");
        for (Map.Entry<String, Integer> r : REGTAB.entrySet()) 
        {
            System.out.println(r.getKey() + "\t\t" + r.getValue());
        }
    }

    static void displayICTAB() 
    {
        System.out.println("\nINTERMEDIATE / ANALYSIS TABLE");
        System.out.println("LC\tIC\tOp1\tOp2");
        for (ICLine ic : ICTAB) 
        {
            if (ic.lc == -1)
                System.out.println("\t" + ic.ic);
            else
                System.out.println(ic.lc + "\t" + ic.ic);
        }
    }

    static void displaySYMTAB() 
    {
        System.out.println("\nSYMBOL TABLE");
        System.out.println("Symbol\tAddress");
        for (Symbol s : SYMTAB.values()) 
        {
            System.out.println(s.name + "\t" + s.address);
        }
    }

    public static void main(String[] args) throws Exception 
    {
        initTables();
        pass1("sample.txt");

        displayOPTAB();
        displayREGTAB();
        displayICTAB();
        displaySYMTAB();
    }
}
