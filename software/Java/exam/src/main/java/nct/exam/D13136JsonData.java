package nct.exam;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.ParameterizedType;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonParser;

/**
 * データをJSON形式で読み書きします。<br>
 * このクラスはすべてstaticなメソッドで構成されています。
 *
 * @author dorayaki4369
 */
public class D13136JsonData {
	/**
	 * JSONファイルにデータを書き込み(上書き)ます。ファイルが存在しない場合は新しく作成します。
	 *
	 * @param object 書き込みたいオブジェクト
	 * @param filename JSONファイルのパス
	 */
	public static void writeData(Object object, String filename) {
		try (FileWriter writer = new FileWriter(filename)) {
			System.out.println("Save the data to " + filename);
			Gson gson = new GsonBuilder().setPrettyPrinting().create();
			String json = gson.toJson(object);
			json = gson.toJson(new JsonParser().parse(json));
			writer.write(json);
			writer.flush();
		}
		catch (IOException e) {
			System.out.println("Failed " + filename);
			e.printStackTrace();
		}
	}

	//Javaのジェネリックはコンパイル時に型が消えるため、動的に見ることはできない。(型消去)
	//Gsonではジェネリック型を(親切に)LinkedTreeMapに変換する。そのため、実行時に本来そこ入るはずの型とLinkedTreeMapが一致しないというエラーを吐く。
	//これを解決するにはParameterizedTypeを実装したジェネリックの型を保存するクラスを作ればいい。
	/**
	 * JSONファイルのデータをコレクション型に復元します。<br>
	 * ファイルがない場合はファイルを新しく作成してArrayList&lt;E&gt;型を返します。
	 *
	 * @param filename JSONファイルのパス
	 * @param clazz コレクションに格納するインスタンスの型情報
	 * @return 復元されたコレクション
	 */
	public static <K> Collection<K> decodeData(String filename, Class<K> clazz) {
		if (!(new File(filename).exists())) {
			System.out.println(filename + " is not found.");
			Collection<K> collection = new ArrayList<>();
			writeData(collection, filename);
			return collection;
		}
		Gson gson = new Gson();
		ParameterizedType type = new D13136GenericType<>(Collection.class, clazz);
		return gson.fromJson(readFile(filename), type);
	}

	/**
	 * JSONファイルのデータをMap&lt;String, E&gt;型に復元します。<br>
	 * ファイルがない場合はファイルを新しく作成してHashMap&lt;String, E&gt;型を返します。
	 *
	 * @param filename JSONファイルのパス
	 * @param clazz マップのValueに格納するインスタンスの型情報
	 * @return 復元されたマップ
	 */
	public static <E> Map<String, E> readData(String filename, Class<E> clazz) {
		if (!(new File(filename).exists())) {
			System.out.println(filename + " is not found.");
			Map<String, E> map = new HashMap<>();
			writeData(map, filename);
			return map;
		}
		Gson gson = new Gson();
		ParameterizedType type = new D13136GenericType<>(Map.class, clazz);
		return gson.fromJson(readFile(filename), type);
	}

	/**
	 * ファイルを読み出します。
	 *
	 * @param filename ファイルのパス
	 * @return file
	 */
	private static String readFile(String filename) {
		String file = "";
		try (FileReader reader = new FileReader(filename)) {
			System.out.println("Loading data from " + filename);
			int i = reader.read();
			while (i != -1) {
				char c = (char) i;
				file = file.concat(String.valueOf(c));
				i = reader.read();
			}
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		return file;
	}
}
